# Time:  O(nlogk)
# Space: O(n)

from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums

        count = Counter(nums)

        # compare each elem of count.key() by putting in
        # count.get method ie comparing by frequencies
        return heapq.nlargest(k, count.keys(), key=count.get)
