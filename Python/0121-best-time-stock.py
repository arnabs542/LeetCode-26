# Time O(n)
# Space O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit, minPrice = 0, float("inf")

        for p in prices:
            minPrice = min(minPrice,p)
            maxProfit = max(maxProfit,p-minPrice)

        return maxProfit
