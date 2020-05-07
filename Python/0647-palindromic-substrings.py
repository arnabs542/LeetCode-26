# Expand from Center Approach:
# Time: O(n^2)
# Space: O(1)
class Solution:
    def countSubstrings(self, s: str) -> int:

        if len(s) < 1:
            return 0

        start, end, result = 0, 0, 0

        for i in range(len(s)):
            left, right = i, i

            while left >=0 and right < len(s) and s[left] == s[right]:
                left-=1
                right+=1
                result+=1

            left, right = i, i+1

            while left>=0 and right < len(s) and s[left] == s[right]:
                left-=1
                right+=1
                result+=1

        return result
