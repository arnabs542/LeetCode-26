# Time O(n^2)
# Space O(1)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            sum = nums[i]*-1
            low, high = i+1, len(nums)-1

            while low<high:
                if nums[low]+nums[high]==sum:
                    result.append([nums[i],nums[low],nums[high]])
                    while low<high and nums[low]==nums[low+1]:
                        low+=1
                    while low<high and nums[high]==nums[high-1]:
                        high-=1
                    low+=1
                    high-+1
                elif nums[low] + nums[high] > sum:
                    high-=1
                else:
                    low+=1
        return result
