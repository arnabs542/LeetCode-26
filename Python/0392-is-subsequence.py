# Time: O(n)
# Space: O(1)
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = j = 0
        while i < len(t) and j < len(s):
            if s[j] ==  t[i]:
                i += 1
                j += 1
            else:
                i += 1
        return j == len(s)

# Notes:
# Greedy algorithm is to find the first even in t
# that is the same as sj
