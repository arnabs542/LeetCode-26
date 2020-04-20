# Time O(n)
# Space O(1)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lookup = {}
        left, result = 0, 0

        for right in range(len(s)):
            if s[right] in lookup:
                left = max(left,lookup[s[right]]+1)
            lookup[s[right]] = right
            result = max(result, right-left+1)

        return result
        
