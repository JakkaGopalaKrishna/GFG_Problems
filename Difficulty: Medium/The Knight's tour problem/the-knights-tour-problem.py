class Solution:
    def knightTour(self, n):
        # Directions a knight can move
        moves = [
            (2, 1), (1, 2), (-1, 2), (-2, 1),
            (-2, -1), (-1, -2), (1, -2), (2, -1)
        ]

        # Initialize the chessboard
        board = [[-1 for _ in range(n)] for _ in range(n)]
        board[0][0] = 0  # starting point

        # Helper function to check valid moves
        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < n and board[x][y] == -1

        # Backtracking function
        def solve(x, y, step):
            if step == n * n:
                return True

            # Try all knight moves
            for dx, dy in moves:
                nx, ny = x + dx, y + dy
                if is_valid(nx, ny):
                    board[nx][ny] = step
                    if solve(nx, ny, step + 1):
                        return True
                    board[nx][ny] = -1  # backtrack

            return False

        # Start the tour
        if solve(0, 0, 1):
            return board
        else:
            return []