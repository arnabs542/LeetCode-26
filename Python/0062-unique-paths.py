# Time:  O(m * n)
# Space: O(x), x = min(m, n)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m < n:
            # grid could be viewed as rotated and
            # answer would still be same
            return self.uniquePaths(n, m)

        # opt[i, 0] = opt[0, j] = 1
        ways = [1] * n

        for i in range(1, m):
            for j in range(1, n):
                # opt[i,j] = opt[i-1,j] + opt[i,j-1]
                ways[j] = ways[j] + ways[j - 1]

        return ways[n-1]

"""
Base case: opt[i, j] = 1 if i = 0 or j = 0
(all down or all right)

ways[1 to n-1] = 1 act as base case for i = 0
and ways[0] = 1 acts as base case for j = 0
"""
