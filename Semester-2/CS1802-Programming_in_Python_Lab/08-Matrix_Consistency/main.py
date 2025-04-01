#!/usr/bin/env python3

import numpy as np


class Determinants:
    def __init__(self, filename: str):
        self.eqn = []

        with open(filename, "r") as file:
            eqnset = []
            for line in file:
                pos = 0
                equation = []

                # Split line into tokens and process each one
                for token in line.split():
                    if token in ("-", "+", " ", "="):
                        continue

                    if pos != 0:
                        if line.split()[pos - 1] == "-":
                            equation.append(-self._coeff(token))
                        else:
                            equation.append(self._coeff(token))
                    else:
                        equation.append(self._coeff(token))
                    pos += 1

                if equation:  # Only add if equation is not empty
                    eqnset.append(equation)

                # Detect empty line to finalize current equation set
                if not line.strip():
                    if eqnset:
                        self.eqn.append((eqnset))
                        eqnset = []  # Reset eqnset for the next group

            # If there are any equations left, append them
            if eqnset:
                self.eqn.append(eqnset)  # In case file does not end with a blank line

    def _coeff(self, inp: str) -> int:
        if inp.isalpha():
            return 1
        elif inp.isnumeric():
            return int(inp)
        elif inp.startswith("-"):
            if (inp[-1]).isalpha():
                return -int(inp[1:-1])
            else:
                return -int(inp[1:])
        else:
            return int(inp[:-1])

    def _extract_matrices(self, equation_set):
        """Extract coefficient matrix A and constant vector B from equations."""
        n_equations = len(equation_set)
        n_variables = len(equation_set[0]) - 1  # Last element is the constant

        A = np.zeros((n_equations, n_variables))
        B = np.zeros((n_equations, 1))

        for i, equation in enumerate(equation_set):
            A[i, :] = equation[:-1]
            B[i, 0] = -equation[
                -1
            ]  # Constants are moved to the right side with opposite sign

        return A, B

    def _calculate_rank(self, matrix):
        """Calculate the rank of a matrix using determinants of submatrices."""
        rows, cols = matrix.shape
        size = min(rows, cols)

        # Check submatrices of decreasing size
        for r in range(size, 0, -1):
            # Check all possible r×r submatrices
            for row_indices in self._get_combinations(range(rows), r):
                for col_indices in self._get_combinations(range(cols), r):
                    submatrix = matrix[np.ix_(row_indices, col_indices)]
                    if (
                        abs(np.linalg.det(submatrix)) > 1e-10
                    ):  # Account for floating point errors
                        return r
        return 0

    def _get_combinations(self, indices, r):
        """Generate all combinations of r elements from indices."""
        if r == 0:
            yield []
            return
        for i, idx in enumerate(indices):
            for combo in self._get_combinations(indices[i + 1 :], r - 1):
                yield [idx] + combo

    def analyze_consistency(self, eq_set_index=0):
        """Analyze the consistency of a system of linear equations."""
        equation_set = self.eqn[eq_set_index]
        A, B = self._extract_matrices(equation_set)

        # Create the augmented matrix
        augmented = np.column_stack((A, B))

        # Calculate ranks
        rank_A = self._calculate_rank(A)
        rank_augmented = self._calculate_rank(augmented)
        n_variables = A.shape[1]

        # Apply the rank conditions
        if rank_A == rank_augmented == n_variables:
            return "Unique solution"
        elif rank_A == rank_augmented < n_variables:
            return "Infinitely many solutions"
        elif rank_A < rank_augmented:
            return "No solution (inconsistent system)"
        else:
            return "Analysis inconclusive"


def main():
    det = Determinants("sample1.txt")

    # Analyze each equation set in the file
    for i, eq_set in enumerate(det.eqn):
        print(f"\nEquation Set {i+1}:")
        print(f"Equations: {eq_set}")
        result = det.analyze_consistency(i)
        print(f"Consistency Analysis: {result}")


if __name__ == "__main__":
    main()
