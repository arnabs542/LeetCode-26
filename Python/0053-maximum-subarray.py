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
opt[i] = maximum sum achieved for an array ending at index
"""

# D & C solution (as in lecture 6)
# Time: O(nlogn)
# Space: O(n), due to stack
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        def helper(l, h):
            if l > h:
                return float("-inf")

            m = l + (h - l)//2
            left_max = helper(l, m-1)
            right_max = helper(m+1, h)

            running_sum, lresult, rresult = 0, 0, 0
            for i in range(m-1, l-1, -1):
                running_sum += nums[i]
                lresult = max(lresult, running_sum)
            running_sum = 0
            for i in range(m+1, h+1, 1):
                running_sum += nums[i]
                rresult = max(rresult, running_sum)
            return max(lresult + rresult + nums[m], left_max, right_max)
        return helper(0, len(nums)-1)

"""
The Divide-and-Conquer algorithm breaks nums into two halves and find the
maximum subarray sum in them recursively. Well, the most tricky part is to
handle the case that the maximum subarray spans the two halves. For this case,
we use a linear algorithm: starting from the middle element and move to both
ends (left and right ends), record the maximum sum we have seen. In this case,
the maximum sum is finally equal to the middle element plus the maximum sum of
moving leftwards and the maximum sum of moving rightwards.

T(n) = 2*T(n/2) + O(n)
"""
