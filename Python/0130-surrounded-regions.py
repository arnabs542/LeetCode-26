# Time:  O(m * n)
# Space: O(m + n)

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) == 0:
            return
        m, n = len(board), len(board[0])

        for i in range(m):
            if board[i][0] == 'O':
                self.boundaryDFS(board, i, 0)
            if board[i][n-1] == 'O':
                self.boundaryDFS(board, i, n-1)

        for j in range(n):
            if board[0][j] == 'O':
                self.boundaryDFS(board, 0, j)
            if board[m-1][j] == 'O':
                self.boundaryDFS(board, m-1, j)

        for i in range(m):
            for j in range(n):
                if (board[i][j] == 'O'):
                    board[i][j] = 'X'
                elif (board[i][j] == '*'):
                    board[i][j] = 'O'

    def boundaryDFS(self, board, i, j):
        if i > len(board) - 1 or i < 0 or j > len(board[0]) - 1 or j < 0:
            return
        if board[i][j] == 'O':
            board[i][j] = '*'

        if i > 0 and board[i-1][j] == 'O':
            self.boundaryDFS(board, i - 1, j)
        if i < len(board) - 1 and board[i+1][j] == 'O':
            self.boundaryDFS(board, i+1, j)
        if j > 0 and board[i][j-1] == 'O':
            self.boundaryDFS(board, i, j - 1)
        if j < len(board[0]) - 1 and board[i][j+1] == 'O':
            self.boundaryDFS(board, i, j+1)
        return
