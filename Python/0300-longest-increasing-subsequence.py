# Time:  O(n^2)
# Space: O(n)
# Traditional DP solution.

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        opt = []
        for i in range(len(nums)):
            opt.append(1)
            for j in range(i):
                if nums[j] < nums[i]:
                    opt[i] = max(opt[i], opt[j] + 1)

        return max(opt) if opt else 0
        # *max_element(opt.begin, opt.end());




# Notes:
# opt[i] represents the length of LIS upto ith index by necessarily including ith
# element.
# opt[i] = (0 <= j < i) max(opt[j] + 1)
