# Tags: Array, Binary Search, Medium
# Time: O(nlogn)
# Space: O(1)

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums) - 1
        ans1 = ans2 = -1
        while left <= right:
            mid = left + (right - left)//2
            if nums[mid] == target:
                ans1 = mid
                right = mid - 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left)//2
            if nums[mid] == target:
                ans2 = mid
                left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return [ans1, ans2]

"""
Finding two points of inflection.
"""
