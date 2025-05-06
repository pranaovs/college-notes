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
            B[i, 0] = equation[-1]

        return A, B

    def row_echelon_form(self, A, B):
        """Transform the coefficient matrix A and constant vector B to row echelon form."""
        # Create copies to avoid modifying the original matrices
        A = A.copy()
        B = B.copy()

        m, n = A.shape  # m rows, n columns

        # Iterate through each column (potential pivot)
        for i in range(min(m, n)):
            # Find the maximum pivot in the current column
            max_row = i
            for j in range(i + 1, m):
                if abs(A[j, i]) > abs(A[max_row, i]):
                    max_row = j

            # Swap rows if necessary
            if max_row != i:
                A[[i, max_row]] = A[[max_row, i]]
                B[[i, max_row]] = B[[max_row, i]]

            # Skip if the pivot is zero (matrix is singular)
            if abs(A[i, i]) < 1e-10:
                continue

            # Eliminate entries below the pivot
            for j in range(i + 1, m):
                factor = A[j, i] / A[i, i]
                A[j, i:] -= factor * A[i, i:]
                B[j] -= factor * B[i]

        return A, B

    def back_substitution(self, A, B):
        """Solve the system Ax=B using back substitution, assuming A is in row echelon form."""
        m, n = A.shape
        x = np.zeros(n)

        # Start from the last row and work upwards
        for i in range(m - 1, -1, -1):
            # Skip rows with all zeros in the coefficient matrix
            if np.all(abs(A[i]) < 1e-10):
                continue

            # Find the first non-zero coefficient (pivot)
            pivot_col = 0
            while pivot_col < n and abs(A[i, pivot_col]) < 1e-10:
                pivot_col += 1

            # If we've gone through all coefficients but the constant is not zero,
            # then the system is inconsistent
            if pivot_col == n:
                if abs(B[i, 0]) >= 1e-10:
                    return "No solution exists (inconsistent system)"
                continue

            # Calculate the value for this variable
            sum_term = 0
            for j in range(pivot_col + 1, n):
                sum_term += A[i, j] * x[j]

            x[pivot_col] = (B[i, 0] - sum_term) / A[i, pivot_col]

        return x

    def solve_system(self, eq_set_index=0):
        """Solve a system of linear equations using row echelon form and back substitution."""
        if eq_set_index >= len(self.eqn):
            return "Invalid equation set index"

        equation_set = self.eqn[eq_set_index]
        A, B = self._extract_matrices(equation_set)

        # Transform to row echelon form
        A_echelon, B_echelon = self.row_echelon_form(A, B)

        # Solve using back substitution
        solution = self.back_substitution(A_echelon, B_echelon)

        # Format the solution
        if isinstance(solution, str):
            return solution
        else:
            return {f"x{i+1}": solution[i] for i in range(len(solution))}


def main():
    det = Determinants("sample1.txt")

    # Analyze each equation set in the file
    for i, eq_set in enumerate(det.eqn):
        print(f"\n{'='*50}")
        print(f"Equation Set {i+1}:")
        print(f"{'-'*50}")

        # Print equations in readable format
        print("Equations:")
        for j, eq in enumerate(eq_set):
            eq_str = ""
            for k, coef in enumerate(eq[:-1]):
                if k > 0:
                    eq_str += (
                        f" {'+' if coef >= 0 else '-'} {abs(coef)}"
                        if abs(coef) != 1
                        else f" {'+' if coef >= 0 else '-'} "
                    )
                else:
                    eq_str += f"{coef}" if abs(coef) != 1 else ""
                eq_str += f"x{k+1}"
            eq_str += f" = {eq[-1]}"
            print(f"  {eq_str}")

        print(f"{'-'*50}")

        # Solve and display results
        result = det.solve_system(i)
        if isinstance(result, dict):
            print("Solution:")
            for var, val in result.items():
                print(f"  {var} = {float(val):.6f}")
        else:
            print(f"Result: {result}")

        print(f"{'='*50}")


if __name__ == "__main__":
    main()
