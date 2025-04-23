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
        n, m = self.optmatrix.shape
        marked = np.zeros((n, m), dtype=int)
        row_covered = np.zeros(n, dtype=bool)
        col_covered = np.zeros(m, dtype=bool)

        # Find a zero in each row
        for i in range(n):
            for j in range(m):
                if (
                    self.optmatrix[i, j] == 0
                    and not row_covered[i]
                    and not col_covered[j]
                ):
                    marked[i, j] = 1
                    row_covered[i] = True
                    col_covered[j] = True

        row_covered.fill(False)
        col_covered.fill(False)

        # Main algorithm loop
        while True:
            # Mark all zeros
            self._mark_zeros(marked, row_covered, col_covered)

            # Check if we have found an optimal assignment
            if np.sum(col_covered) == min(n, m):
                break

            # Find the smallest uncovered value
            min_val = float("inf")
            for i in range(n):
                for j in range(m):
                    if not row_covered[i] and not col_covered[j]:
                        min_val = min(min_val, self.optmatrix[i, j])

            # Adjust the matrix
            for i in range(n):
                for j in range(m):
                    if row_covered[i] and col_covered[j]:
                        self.optmatrix[i, j] += min_val
                    elif not row_covered[i] and not col_covered[j]:
                        self.optmatrix[i, j] -= min_val

        self.marked = marked

    def _mark_zeros(self, marked, row_covered, col_covered):
        n, m = self.optmatrix.shape

        # Mark all columns having assignments
        for j in range(m):
            for i in range(n):
                if marked[i, j] == 1:
                    col_covered[j] = True

        # Repeat until no uncovered zeros found
        while True:
            # Find an uncovered zero
            i, j = -1, -1
            for r in range(n):
                if row_covered[r]:
                    continue
                for c in range(m):
                    if not col_covered[c] and self.optmatrix[r, c] == 0:
                        i, j = r, c
                        break
                if i != -1:
                    break

            if i == -1:  # No uncovered zeros
                return

            # Mark the zero and cover its row
            marked[i, j] = 2  # Mark as an auxiliary zero
            row_covered[i] = True

            # Check if there's an assignment in this row
            starred_col = -1
            for c in range(m):
                if marked[i, c] == 1:
                    starred_col = c
                    break

            if starred_col != -1:
                # Uncover row, cover the column with assignment
                row_covered[i] = False
                col_covered[starred_col] = True
            else:
                # Augment path starting with this zero
                self._augment_path(marked, i, j)
                row_covered.fill(False)
                col_covered.fill(False)
                return

    def _augment_path(self, marked, row, col):
        # Store the sequence of starred and primed zeros
        path = [(row, col)]
        n, m = self.optmatrix.shape

        while True:
            # Find a starred zero in the same column
            starred_row = -1
            for i in range(n):
                if marked[i, path[-1][1]] == 1:
                    starred_row = i
                    break

            if starred_row == -1:
                break

            # Add the starred zero to the path
            path.append((starred_row, path[-1][1]))

            # Find a primed zero in the same row
            primed_col = -1
            for j in range(m):
                if marked[path[-1][0], j] == 2:
                    primed_col = j
                    break

            path.append((path[-1][0], primed_col))

        # Convert path alternating sequence
        for i, (r, c) in enumerate(path):
            if i % 2 == 0:  # Even index: primed zeros become starred
                marked[r, c] = 1
            else:  # Odd index: starred zeros become unstarked
                marked[r, c] = 0

    def get_assignment(self):
        if not hasattr(self, "marked"):
            return None

        n, m = self.optmatrix.shape
        assignment = []

        for i in range(n):
            for j in range(m):
                if self.marked[i, j] == 1:
                    assignment.append((i, j))

        return assignment

    def get_optimal_cost(self):
        assignment = self.get_assignment()
        if not assignment:
            return None

        total_cost = 0
        for i, j in assignment:
            total_cost += self.matrix[i, j]

        return total_cost


def main():
    inputs = []
    with open("Sample11.txt", "r") as f:
        matrix = []
        for line in f:
            if line == "\n":
                if matrix:
                    inputs.append(matrix)
                    matrix = []
            else:
                matrix.append(list(map(int, line.split())))
        inputs.append(matrix)

    for inp in inputs:
        trnspt = Transport(inp)
        trnspt.optimize()
        print("Optimized matrix:")
        print(trnspt.optmatrix)
        print("Assignment:", trnspt.get_assignment())
        print("Optimal cost:", trnspt.get_optimal_cost())


if __name__ == "__main__":
    main()
