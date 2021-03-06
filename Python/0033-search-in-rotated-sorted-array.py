# Time O(logn)
# Space O(1)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if(len(nums)==0):
            return -1

        left, right = 0, len(nums)-1

        ans = -1
        while left <= right:
            mid = left + (right-left)//2

            if(nums[mid] <= nums[len(nums)-1]):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        inflect = ans
        left, right = 0, len(nums)-1

        if (nums[inflect]<=target<=nums[right]):
            left = inflect
        else:
            right = inflect-1

        while left<=right:
            mid = left + (right-left)//2

            if nums[mid] == target:
                return mid
            elif nums[mid]<target:
                left = mid+1
            else:
                right = mid-1

        return -1
