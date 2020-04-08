#Time: O(n)
#Space: O(1)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if not nums:
            return []

        leftProduct = [1 for _ in range(len(nums))]

        for i in range(1,len(nums)):
            leftProduct[i] = leftProduct[i-1]*nums[i-1]

        rightProduct = 1

        for i in reversed(range(len(nums)-1)):
            rightProduct*=nums[i+1]
            leftProduct[i]*=rightProduct

        return leftProduct
