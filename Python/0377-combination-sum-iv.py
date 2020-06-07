# Time: O(nlon + n * t), t is the value of target.
# Space: O(t)
# DP Bottom-Up Approach
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        nums.sort()
        for i in range(1, target + 1):
            for j in range(len(nums)):
                if nums[j] <= i:
                    dp[i] += dp[i - nums[j]]
                else:
                    break
        return dp[target]

# Notes:
# Sorting is not necessary. It just helps to avoid unnecessary iterations
# as if nums[j] is not <= target, we can break for nums[j+1] onwards.
