# DP
# Time: O(m * n)
# Space: O(m * n)
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [[0]*n for _ in range(m)]
        result = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    dp[i][j] = 1
                    if i > 0 and j > 0:
                        dp[i][j] += min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
                result = max(result, dp[i][j])

        return result*result

# Notes:
# opt[i, j] represents the side of biggest square that can be drawn
# having matrix[i,j] as the bottom right element.

# DP using two colums
# Time: O(m * n)
# Space: O(n)
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        pre = [0] * n
        cur = [0] * n
        result = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    cur[j] = 1
                    if i > 0 and j > 0:
                        cur[j] += min(pre[j-1], cur[j-1], pre[j])
                result = max(result, cur[j])
            pre = cur
            cur = [0]*len(cur)

        return result*result

# To do using just one column
