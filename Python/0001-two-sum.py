#time = O(n)
#space = O(n)
class Solution:
    def twoSum(self, nums, target: int):
        lookup= {}
        for i,num in enumerate(nums):
            if target-num in lookup:
                return [lookup[target-num],i]
            lookup[num] = i
