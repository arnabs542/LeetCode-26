# Time:  O(n * s), s is the sum of nums
# Space: O(n*s)
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)
        # checking if sum is odd
        if target & 1 == 1:
            return False
        target //= 2
        dp = [[False for __ in range(target+1)] for _ in range(len(nums)+1)]

        # Base Case
        for k in range(len(nums)+1):
            dp[k][0] = True

        # if we interchange loops, no change in result
        for k in range(1, len(nums) + 1):
            for x in range(1, target + 1):
                if x - nums[k-1] < 0:
                    continue
                dp[k][x] = (dp[k-1][x - nums[k-1]] or dp[k-1][x])
        return dp[len(nums)][target]


# Notes:
# We essentially just need to find a subset such that sum(subset) = total sum/2
# This also means that the total sum has to be even, otherwise there can't be
# a subset with +ve integers having sum(subset) = total sum/2
#
# OPT[k, x] = true if a subset of sum x can be created using first k numbers
# Base case: OPT[0][0] = true (zero number consists of sum 0)
# OPT[k, x] = (OPT[k-1, x-xk] || OPT[k-1, x])
# Since there is k-1 is both expressions, we can optimize in space
# Actually, this is a 0/1 knapsack problem, for each number, we can pick it or not.



# Time: O(n*s)
# Space: O(s)
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)
        # checking if sum is odd
        if target % 2:
            return False
        target //= 2
        dp = [False for _ in range(target + 1)]

        # Base Case
        dp[0] = True

        # interchanging loops will not work here
        for k in range(1, len(nums) + 1):
            # or use revered(range(1, target+1))
            for x in range(target, 0, -1):
                if x - nums[k-1] < 0:
                    continue
                dp[x] = (dp[x - nums[k-1]] or dp[x])
        return dp[-1]



# Notes:
# It is necessary to iterate x from right to left here.

# If we go from left to right, we would end up have

# DP[k, x] = DP[k-1][x] or DP[k][x-num] since DP[k-1][x-num]
# value has already been replaced with DP[k][x-num]
