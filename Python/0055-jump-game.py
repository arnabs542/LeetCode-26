# Time:  O(n)
# Space: O(1)

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lastGoodIndexPos = len(nums) - 1
        for i, n in reversed(list(enumerate(nums))):
            if (n >= lastGoodIndexPos - i):
                lastGoodIndexPos = i
        return lastGoodIndexPos == 0


"""
As expected Greedy solution takes less time than DP solution.
Greedy Choice property: take the last good index position

Optimal substructure: at each iteration, we've a local optimal
solution to our subproblem.

If we went from left to right, for each index, we might have to
check every index before it.
But since we go from right to left, we only interate the list once.
"""
