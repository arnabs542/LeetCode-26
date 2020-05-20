# Time O(n)
# Space O(n)


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        result, nums = 0, set(nums)

        for x in nums:
            if x - 1 not in nums:
                y = x + 1
                while y in nums:
                    y += 1
                result = max(result, y - x)
        return result
