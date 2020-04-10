# Time O(n)
# Space O(1)

class Solution:
    def maxProduct(self, nums) :
        pdb.set_trace()
        result = nums[0]
        localMin = nums[0]
        localMax= nums[0]

        for i in range(1,len(nums)):
            if(nums[i]>0):
                localMax, localMin = max(localMax*nums[i],nums[i]), min(localMin*nums[i],nums[i])
            else:
                localMax, localMin = max(localMin*nums[i],nums[i]), min(localMax*nums[i],nums[i])

            result = max(result,localMax)

        return result
