# Time:  O(m * n * l)
# Space: O(l)

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        def dfs(i, j, found, c):
            if len(found) == len(word):
                return True

            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return False

            if word[c] != board[i][j]:
                return False

            board[i][j] = '#'

            for it, jt in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                if dfs(it, jt, found + word[c], c + 1):
                    return True

            board[i][j] = word[c]

            return False


        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, "", 0):
                    return True

        return False
