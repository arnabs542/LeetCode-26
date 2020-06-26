# Time:  O(n^2)
# Space: O(n)
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        nums.sort()
        dp = [1] * len(nums)
        prev = [-1] * len(nums)
        largest_idx = 0
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        prev[i] = j
            if dp[largest_idx] < dp[i]:
                largest_idx = i

        result = []
        i = largest_idx
        while i != -1:
            result.append(nums[i])
            i = prev[i]
        return result[::-1]


# Notes:
# -Variant of Largest Increasing Subset
# -Cond: Current element is divisible by previous elements (since sorted)
# -If not sorted, check both a%b and b%a
# -if b%a = 0 & c%b = 0 then c%a = 0 (Transitive property)
# -dp[i] denotes the length of largest subset including the current element
# nums[i]
