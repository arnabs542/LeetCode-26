# Time:  O(n)
# Space: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Treat each (index, value) pair of the array as
        # (pointer, next) node thus duplicated number will
        # be the begin of the cycle in linked list
        slow = 0
        fast = 0
        while 1:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        fast = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow



# Time:  O(nlogn), search logn times
# Space: O(1)
# Binary search method.
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # Treat each (index, value) pair of the array as
        # (pointer, next) node thus duplicated number will
        # be the begin of the cycle in linked list
        left, right = 1, len(nums) - 1
        ans = 1
        # At first the search space is numbers between 1 to n
        while left <= right:
            mid = left + (right - left)//2
            count = 0
            for num in nums:
                if num <= mid:
                    count += 1
            if count > mid:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
