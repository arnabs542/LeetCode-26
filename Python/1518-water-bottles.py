class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        empty, result = numBottles, numBottles
        while empty >= numExchange:
            q, r = divmod(empty, numExchange)
            result += q
            empty = q + r
        return result
        
