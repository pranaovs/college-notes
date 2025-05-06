import numpy as np


class Transport:

    def __init__(self, matrix):
        self.matrix = np.asarray(matrix)
        self.optmatrix = self.matrix.copy()  # Create a copy instead of reference

    def _row_minima(self):
        mins = []
        for row in self.optmatrix:
            mins.append(min(row))
        return mins

    def _row_optimize(self):
        mins = self._row_minima()
        for i in range(0, len(mins)):
            self.optmatrix[i] -= mins[i]

    def _column_minima(self):
        mins = []
        for j in range(self.optmatrix.shape[1]):
            col_min = float("inf")
            for i in range(self.optmatrix.shape[0]):
                if self.optmatrix[i][j] < col_min:
                    col_min = self.optmatrix[i][j]
            mins.append(col_min)
        return mins

    def _column_optimize(self):
        mins = self._column_minima()
        for j in range(len(mins)):
            for i in range(self.optmatrix.shape[0]):
                self.optmatrix[i][j] -= mins[j]

    def optimize(self):
        self._row_optimize()
        self._column_optimize()
        self._hungarian_algorithm()

    def _hungarian_algorithm(self):
        """
        Implementation of the Hungarian algorithm for assignment problem.
        This function finds an optimal assignment.
        """
        n, m = self.optmatrix.shape

        # Make the matrix square if it's not already
        # This ensures the algorithm works for non-square matrices
        if n != m:
            max_dim = max(n, m)
            square_matrix = np.zeros((max_dim, max_dim))
            square_matrix[:n, :m] = self.optmatrix
            self.optmatrix = square_matrix
            n = m = max_dim

        # Step 1: Reduce matrix by subtracting row and column minimums
        # (This is already done by _row_optimize and _column_optimize)

        # Step 2: Find a zero in each row/column to get initial feasible solution
        starred = np.zeros((n, m), dtype=bool)
        covered_rows = np.zeros(n, dtype=bool)
        covered_cols = np.zeros(m, dtype=bool)

        # Find zeros and star them (no two in same row/column)
        for i in range(n):
            for j in range(m):
                if (
                    self.optmatrix[i, j] == 0
                    and not covered_rows[i]
                    and not covered_cols[j]
                ):
                    starred[i, j] = True
                    covered_rows[i] = True
                    covered_cols[j] = True

        # Reset covering vectors
        covered_rows.fill(False)
        covered_cols.fill(False)

        # Main algorithm loop
        max_iterations = n * m * 2  # Safety to prevent infinite loops
        iteration = 0

        while not np.all(covered_cols) and iteration < max_iterations:
            iteration += 1

            # Step 3: Cover all columns with starred zeros
            for j in range(m):
                if any(starred[:, j]):
                    covered_cols[j] = True

            # Check if we're done
            if np.sum(covered_cols) == min(n, m):
                break

            # Step 4: Find uncovered zero and prime it
            while True:
                # Find an uncovered zero
                i, j = self._find_uncovered_zero(covered_rows, covered_cols)

                if i == -1:  # No uncovered zeros
                    # Step 6: Update matrix - add/subtract min value
                    self._update_matrix(covered_rows, covered_cols)
                    continue  # Go back to finding an uncovered zero

                # Prime the zero
                primed = np.zeros((n, m), dtype=bool)
                primed[i, j] = True

                # Check if there's a starred zero in the same row
                j_star = -1
                for j2 in range(m):
                    if starred[i, j2]:
                        j_star = j2
                        break

                if j_star >= 0:
                    # Cover the row and uncover the column with the starred zero
                    covered_rows[i] = True
                    covered_cols[j_star] = False
                else:
                    # Step 5: Augmenting path - convert primed to starred
                    self._augment_path(starred, primed, i, j)
                    # Reset covers for next iteration
                    covered_rows.fill(False)
                    covered_cols.fill(False)
                    break

        # Final assignment
        self.assignment = []
        for i in range(min(n, self.matrix.shape[0])):
            for j in range(min(m, self.matrix.shape[1])):
                if starred[i, j]:
                    self.assignment.append((i, j))

    def _find_uncovered_zero(self, covered_rows, covered_cols):
        """Find an uncovered zero in the matrix"""
        n, m = self.optmatrix.shape
        for i in range(n):
            if covered_rows[i]:
                continue
            for j in range(m):
                if not covered_cols[j] and self.optmatrix[i, j] == 0:
                    return i, j
        return -1, -1

    def _update_matrix(self, covered_rows, covered_cols):
        """Update the matrix by adding/subtracting the minimum value"""
        n, m = self.optmatrix.shape

        # Find the minimum uncovered value
        min_val = float("inf")
        for i in range(n):
            if covered_rows[i]:
                continue
            for j in range(m):
                if not covered_cols[j]:
                    min_val = min(min_val, self.optmatrix[i, j])

        if min_val == float("inf"):
            return  # Safety check

        # Add min to covered rows
        for i in range(n):
            if covered_rows[i]:
                for j in range(m):
                    self.optmatrix[i, j] += min_val

        # Subtract min from uncovered columns
        for j in range(m):
            if not covered_cols[j]:
                for i in range(n):
                    self.optmatrix[i, j] -= min_val

    def _augment_path(self, starred, primed, row, col):
        """Augment path starting with primed zero at (row, col)"""
        n, m = self.optmatrix.shape

        # Construct the path
        path = [(row, col)]

        while True:
            # Find a starred zero in the column of the last path element
            row_star = -1
            col_star = path[-1][1]

            for i in range(n):
                if starred[i, col_star]:
                    row_star = i
                    break

            if row_star == -1:
                break

            # Add the starred zero to the path
            path.append((row_star, col_star))

            # Find a primed zero in the row of the starred zero
            col_prime = -1
            row_prime = path[-1][0]

            for j in range(m):
                if primed[row_prime, j]:
                    col_prime = j
                    break

            if col_prime == -1:
                # If this happens, there's a problem with the algorithm logic
                break

            # Add the primed zero to the path
            path.append((row_prime, col_prime))

        # Augment the path - toggle starred status
        for i, j in path:
            starred[i, j] = not starred[i, j]

        return starred

    def get_assignment(self):
        if hasattr(self, "assignment"):
            return self.assignment
        return None

    def get_optimal_cost(self):
        assignment = self.get_assignment()
        if not assignment:
            return None

        total_cost = 0
        for i, j in assignment:
            if i < self.matrix.shape[0] and j < self.matrix.shape[1]:
                total_cost += self.matrix[i, j]

        return total_cost


def main():
    inputs = []
    with open("Sample11.txt", "r") as f:
        matrix = []
        for line in f:
            line = line.strip()
            if not line:  # Empty line
                if matrix:
                    inputs.append(matrix)
                    matrix = []
            else:
                matrix.append(list(map(int, line.split())))
        if matrix:  # Don't forget the last matrix
            inputs.append(matrix)

    for i, inp in enumerate(inputs):
        print(f"\nTest Case {i+1}:")
        trnspt = Transport(inp)
        trnspt.optimize()
        print("Assignment:", trnspt.get_assignment())
        print("Optimal cost:", trnspt.get_optimal_cost())


if __name__ == "__main__":
    main()
