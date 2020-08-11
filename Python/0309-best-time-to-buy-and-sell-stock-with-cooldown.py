# Time:  O(n)
# Space: O(n*2) -> O(n)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        if len(prices) == 2:
            return max(0, prices[1] - prices[0])

        # n rows and 2 columns
        dp = [[0]*2 for _ in range(len(prices))]

        dp[0][0] = 0
        dp[0][1] = -prices[0]
        dp[1][0] = max(-prices[0] + prices[1], 0)
        dp[1][1] = max(-prices[0], 0 - prices[1])

        for i in range(2, len(prices)):
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0])
            dp[i][1] = max(dp[i-2][0] - prices[i], dp[i-1][1])

        return dp[len(prices)-1][0]


"""
Notes:
OPT[i][0]: represents the maximum profit earned until ith day if we don't
have a stock on ith day
OPT[i][1]: represents the maximum profit earned until ith day if we have
a stock on ith day.

Case 1: OPT[i][0]: We don't have a stock : MAX of the following

a.  Sold today
    OPT[i-1][1] + prices[i]

b.   Carry forward
    OPT[i-1][0]



Case 2: OPT[i][1]: We have a stock : MAX of the following

a. Bought today
    OPT[i-2][0] - prices[i]

b. Carry forward
    OPT[i-1][1]

"""
