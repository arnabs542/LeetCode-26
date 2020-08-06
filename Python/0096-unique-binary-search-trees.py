# Tags: DP
# Time: O(n^3)
# Space: O(n^2)
# DP solution.
class Solution:
    def numTrees(self, n: int) -> int:
        if n < 3:
            return n

        dp = [[0] * n for _ in range(n)]

        for i in range(n):
            dp[i][i] = 1

        # n+1 since length
        for l in range(1, n+1):
            for i in range(n-l):
                j = i + l
                for r in range(i, j+1):
                    if r == i:
                        # only right
                        dp[i][j] += dp[r+1][j]
                    elif r == j:
                        # only left
                        dp[i][j] += dp[i][r-1]
                    else:
                        dp[i][j] += dp[i][r-1]*dp[r+1][j]

        return dp[0][n-1]


#     Notes:
#     OPT[i, j] = number of BST that can be formed with element ki, ...... kj
#     where k1 < k2 < ..... < kn (sorted)
#     OPT[i, j] = sum i <= r <= j (OPT[i, r-1]*OPT[r+1, j])
#     Base Case: OPT[i,i] = 1

#     For each r as root, number of BST for [i, j] will be the product of number of
#     BST for [i, r-1] and for [r+1, j] (left and right subtrees are independent)
#     Now, total number of BST using elements from i to j will be the sum of
#     instances where root can take positions from i to j


# Time:  O(n^2)
# Space: O(n)
# DP solution.
class Solution:
    def numTrees(self, n: int) -> int:
        if n < 3:
            return n

        dp = [0] * (n+1)
        # for only left or only right
        dp[0] = 1
        # just 1 elem
        dp[1] = 1
        for l in range(2, n+1):
            for leftLen in range(l):
                dp[l] += dp[leftLen]*dp[l-leftLen-1]
        return dp[n]


# Notes:
# Sometimes the definition of interval can influence the algorithm performance
# If we find the relationships between intervals, they might be able to be merged
# Here is that, # of BST from [1 ~ 3] == # of BST from [2 ~ 4], and etc.
#
# Earlier we had
# dp[i][j] =
# of BST can be constructed from i to j
# Now we can have
# dp[l] = # of BST can be constructed with l consecutive numbers

# To Do: using combination formula
