# Time O(n)
# Space O(1)
class Solution:
    def longestPalindrome(self, s: str) -> str:

        def expandFromMiddle(s, left, right):
            if left > right:
                return 0

            while left >=0 and right < len(s) and s[left] == s[right]:
                left-=1
                right+=1

            return right-left-1

        if len(s) < 1:
            return ""
        start, end = 0, 0

        for i in range(len(s)):
            len1 = expandFromMiddle(s,i,i)
            len2 = expandFromMiddle(s,i,i+1)
            length = max(len1,len2)
            if length > end-start+1:
                start = i - (length-1)//2
                end = i + length//2;

        return s[start:end+1]
    
