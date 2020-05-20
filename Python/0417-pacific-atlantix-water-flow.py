# Time O(m*n)
# Space O(m*n)


class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:

        PACIFIC, ATLANTIC = 1, 2

        def dfs(matrix, x, y, prevVal, curOceanNum, visited, res):
            if (not 0 <= x < len(matrix)) or (not 0 <= y < len(matrix[0])) or matrix[x][y] < prevVal or \
            (visited[x][y] | curOceanNum) == visited[x][y]:
                return

            visited[x][y] |= curOceanNum

            if visited[x][y] == (PACIFIC | ATLANTIC):
                res.append((x,y))

            for d in [(0,-1), (0,1), (-1,0), (1,0)]:
                dfs(matrix, x + d[0], y + d[1], matrix[x][y], visited[x][y], visited, res)

        if not matrix:
            return []

        res = []

        m, n = len(matrix), len(matrix[0])

        visited = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            dfs(matrix, i, 0, float("-inf"), PACIFIC, visited, res)
            dfs(matrix, i, n - 1, float("-inf"), ATLANTIC, visited, res)
        for j in range(n):
            dfs(matrix, 0, j, float("-inf"), PACIFIC, visited, res)
            dfs(matrix, m - 1, j, float("-inf"), ATLANTIC, visited, res)

        return res
        
