# Time:  O(n)
# Space: O(n)

import collections
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # key = cummulative sum
        # value = no. of times it appeared
        lookup = collections.defaultdict(int)
        result = 0
        accumulated_sum = 0
        lookup[0] += 1
        for num in nums:
            accumulated_sum += num
            result += lookup[accumulated_sum-k]
            lookup[accumulated_sum] += 1
        return result




# Notes:
# If the cumulative sum upto two indices is at a difference
# of k, the sum of elements lying in between those indices
# is k. For each index i, we have to iterate j backwards as
# there may be multiple instances of cum_sum[i] - cum_sum[j]
# == k.
# We can instead use a hash map to register the num of times
# a particular cummulative sum appears.
