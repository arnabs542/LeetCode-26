# Time:  O(n)
# Space: O(1)

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lastGoodIndexPos = len(nums) - 1
        for i, n in reversed(list(enumerate(nums))):
            if (i + n >= lastGoodIndexPos):
                lastGoodIndexPos = i
        return lastGoodIndexPos == 0


# Notes:
# As expected Greedy solution takes less time than DP solution.
# Greedy Choice property: take the last good index position
# Optimal substructure: at each iteration, we've a local optimal
# solution to our subproblem.
