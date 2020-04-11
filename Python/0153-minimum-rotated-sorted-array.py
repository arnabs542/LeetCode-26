class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1
        target = nums[0]

        if nums[right] > nums[left]:
            return nums[0]

        while (left<right):
            mid = int(left + (right-left)/2)

            if (nums[mid] >= target):
                left = mid+1
            else:
                right = mid

        return nums[right]



#better
class Solution2:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1

        while (left<right):
            mid = left + (right-left)//2

            if (nums[mid] < nums[right]):
                right = mid
            else:
                left = mid + 1

        return nums[left]
