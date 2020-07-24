class Solution:
    def numSub(self, s: str) -> int:
        result = 0
        for sub in s.split('0'):
            result += len(sub)*(len(sub) + 1)//2
        return result % (10**9 + 7)

# Notes:
#     Can use sliding window approach
#     or
#     Normal counting of natural numbers
