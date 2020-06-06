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
