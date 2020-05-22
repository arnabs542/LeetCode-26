# Time:  O(n)
# Space: O(1)

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sum = len(nums)*(len(nums) + 1)//2

        for i,n in enumerate(nums):
            sum -= n

        return sum

"""
Notes:
can also be done using divide and conquer
"""
