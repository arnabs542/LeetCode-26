# Time O(n)
# Space O(1)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        result, opt = float("-inf"), float("-inf")

        for n in nums:
            opt = max(opt+n,n)
            result = max(result,opt)

        return result


"""
Notes: opt[i] = maximum sum achieved for an array ending
at index
"""
