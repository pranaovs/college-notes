#!/usr/bin/env python3
# List to keep track of visited positions to avoid revisiting
explored = []


def check(start, end, matrix):
    """
    Main path-finding function that uses depth-first search to find a path
    from start position to end position in the given matrix.

    Args:
        start: Starting position as (row, col) tuple
        end: Target position as (row, col) tuple
        matrix: 2D grid where 0=path, 1=wall, 2=start, 3=end
    """
    if start == end:
        print("Result found")
    else:
        # Stack for DFS (depth-first search) implementation
        stack = []
        pos = start
        while True:
            # Flag to track if any valid moves were found
            found_valid_move = False

            if pos == (3, 4):
                print("")  # Debug print

            # Check all four possible directions (top, right, down, left)
            if topcheck(matrix, pos):
                stack.append((pos[0] - 1, pos[1]))
                found_valid_move = True

            if rightcheck(matrix, pos):
                stack.append((pos[0], pos[1] + 1))
                found_valid_move = True

            if downcheck(matrix, pos):
                stack.append((pos[0] + 1, pos[1]))
                found_valid_move = True

            if leftcheck(matrix, pos):
                stack.append((pos[0], pos[1] - 1))
                found_valid_move = True

            # Mark current position as visited
            explored.append(pos)

            # If no more positions to explore, path is impossible
            if stack == []:
                print("No solution found")
                break

            # Get next position to explore from stack (DFS behavior)
            pos = stack.pop()

            # Check if we've reached the destination
            if pos == end:
                print("Solution found")
                break
    return


def downcheck(matrix, pos):
    """
    Check if moving down from current position is valid.

    Args:
        matrix: The maze grid
        pos: Current position as (row, col)

    Returns:
        Boolean indicating if down movement is valid
    """
    if pos in explored:  # Skip if current position already explored
        return False
    else:
        # Check if down position is within matrix bounds
        if pos[0] + 1 < len(matrix):
            checker = (pos[0] + 1, pos[1])
            # Check if down cell is a path (0) or end (3) and not already explored
            if matrix[pos[0] + 1][pos[1]] in (0, 3) and checker not in explored:
                return True
            else:
                return False
        else:
            return False


def rightcheck(matrix, pos):
    """
    Check if moving right from current position is valid.

    Args:
        matrix: The maze grid
        pos: Current position as (row, col)

    Returns:
        Boolean indicating if right movement is valid
    """
    if pos in explored:  # Skip if current position already explored
        return False
    else:
        # Check if right position is within matrix bounds
        if pos[1] + 1 < len(matrix[pos[0]]):
            checker = (pos[0], pos[1] + 1)
            # Check if right cell is a path (0) or end (3) and not already explored
            if matrix[pos[0]][pos[1] + 1] in (0, 3) and checker not in explored:
                return True
            else:
                return False
        else:
            return False


def topcheck(matrix, pos):
    """
    Check if moving up from current position is valid.

    Args:
        matrix: The maze grid
        pos: Current position as (row, col)

    Returns:
        Boolean indicating if up movement is valid
    """
    if pos in explored:  # Skip if current position already explored
        return False
    else:
        # Check if top position is within matrix bounds
        if (pos[0] - 1) >= 0:
            checker = (pos[0] - 1, pos[1])
            # Check if top cell is a path (0) or end (3) and not already explored
            if matrix[pos[0] - 1][pos[1]] in (0, 3) and checker not in explored:
                return True
            else:
                return False
        else:
            return False


def leftcheck(matrix, pos):
    """
    Check if moving left from current position is valid.

    Args:
        matrix: The maze grid
        pos: Current position as (row, col)

    Returns:
        Boolean indicating if left movement is valid
    """
    if pos in explored:  # Skip if current position already explored
        return False
    else:
        # Check if left position is within matrix bounds
        if (pos[1] - 1) >= 0:
            checker = (pos[0], pos[1] - 1)
            # Check if left cell is a path (0) or end (3) and not already explored
            if matrix[pos[0]][pos[1] - 1] in (0, 3) and checker not in explored:
                return True
            else:
                return False
        else:
            return False


# Define the maze matrix:
# 0 = open path
# 1 = wall
# 2 = start position
# 3 = end/goal position
MAT = [
    [2, 0, 0, 0, 0],
    [1, 1, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 3],
]

# Find start position (marked as 2) in the matrix
st = [(i, j) for i in range(len(MAT)) for j in range(len(MAT[i])) if MAT[i][j] == 2]
# Find end position (marked as 3) in the matrix
en = [(i, j) for i in range(len(MAT)) for j in range(len(MAT[i])) if MAT[i][j] == 3]

# Run the pathfinding algorithm from start to end
check(st[0], en[0], MAT)
