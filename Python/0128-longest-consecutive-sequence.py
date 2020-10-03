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
# Starting from each element x, we go as far as the count of consecutive
# elements can go.
# We only attempt to build sequences from numbers that
# are not already part of a longer sequence, ie only if
# x-1 is not in the set.
# O(n) because we skip if x-1 is present in the set and only iterative once.
# corner example : 6, 5, 4, 3, 2, 1
