# Time:  O(n)
# Space: O(1)
# Linked list (beginning of the cycle) solution
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
        # Start with a search space of length n and keep
        # reducing the search space until the result is found
        left, right = 1, len(nums) - 1
        ans = 1
        # At first the search space (list of possible answers)
        # is numbers between 1 to n [1,n] (not the nums array)
        while left <= right:
            mid = left + (right - left)//2
            count = 0
            # number of elements in nums that fall in our search
            # space
            for num in nums:
                # at each iteration we search in the range [1:mid + 1]
                # and ask how many numbers <= mid?
                if num <= mid:
                    count += 1
            if count > mid:
                # region of interest
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans

# Notes:
# Let count be the number of elements in nums that fall in the search space
# range [1, mid].
#
# If count > mid, then there are more than 'mid' no. of elements in the range [1, mid] and
# thus that range contains a duplicate.
#
# If count <= mid, then there are n+1-count elements in the range [mid+1, n].
# That is, n+1-mid elements in a range of size n-mid. Thus this range
# must contain a duplicate.
#
# (In true nums (no duplicate), count equals mid)
