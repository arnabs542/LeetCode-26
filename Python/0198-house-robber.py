# Time:  O(n)
# Space: O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        last, result = 0, 0
        for n in nums:
            tmp = result
            result = max(result, last + n)
            last = tmp
            # or last, now = now, max(last + i, now)
        return result



# Notes:
# result behaves as opt[i-1] and last behaves as opt[i-2]
