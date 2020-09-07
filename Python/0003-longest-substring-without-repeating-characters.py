# Time O(n)
# Space O(1), since only 26 characterss

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lookup = {}
        left, result = 0, 0

        for right in range(len(s)):
            if s[right] in lookup:
                # max ensures left pointer either stays where it is
                # or shifted to right but never moves back to left
                left = max(left,lookup[s[right]]+1)
            lookup[s[right]] = right
            result = max(result, right-left+1)

        return result
