# Failed Attempt: Time limit exceeded
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        self.result = float("inf")
        def dfs(sum, i, j):
            if i == m-1 and j == n-1:
                sum += grid[i][j]
                self.result = min(self.result, sum)
                return

            if i < 0 or i > m-1 or j < 0 or j > n-1:
                return

            if grid[i][j] == -1 or sum > self.result:
                return

            val = grid[i][j]
            grid[i][j] = -1

            for ii, jj in (0, +1), (0, -1), (+1, 0), (-1, 0):
                dfs(sum + val, i + ii, j + jj)

            grid[i][j] = val

        dfs(0, 0, 0)
        return self.result



# DP (using two colums)
# Time:  O(m * n)
# Space: O(m)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cur = [grid[0][0]]*m
        prev = [grid[0][0]]*m
        for i in range(1, m):
            prev[i] = prev[i-1] + grid[i][0]

        for j in range(1, n):
            cur[0] = prev[0] + grid[0][j]
            for i in range(1, m):
                cur[i] = min(prev[i], cur[i-1]) + grid[i][j]
            prev = cur

        return prev[m-1]


# DP (using one column)
# inspecting the above code, it can be seen that maintaining
# pre is for recovering pre[i], which is simply cur[i] before
# its update. So it is enough to use only one vector.
# Time: O(m * n)
# Space: O(m)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cur = [grid[0][0]]*m
        for i in range(1, m):
            cur[i] = cur[i-1] + grid[i][0]

        for j in range(1, n):
            cur[0] += grid[0][j]
            for i in range(1, m):
                cur[i] = min(cur[i], cur[i-1]) + grid[i][j]

        return cur[m-1]



# Notes:
# Base case occur at the first column and first row.
# Here the minimum sum at each point is the accumulation
# of previous points.
