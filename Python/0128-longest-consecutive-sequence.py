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


# Notes:
# Starting from x, how far the count of consecutive
# elements can go
# we only attempt to build sequences from numbers that
# are not already part of a longer sequence
# corner example : 6, 5, 4, 3, 2, 1
