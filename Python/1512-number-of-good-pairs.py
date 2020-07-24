import collections
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        result = 0
        counter = collections.Counter()
        for i, n in enumerate(nums):
            counter[n] += 1
        result = sum(k*(k-1)/2 for k in counter.values())
        return int(result)

        
