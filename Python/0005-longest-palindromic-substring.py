# Time O(n^2)
# Space O(1)
# Expand from middle approach
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
                # in case of aabbaa, i is not at center
                # but length is even therefore length - 1 for start
                start = i - (length-1)//2
                end = i + length//2;

        return s[start:end+1]


# Time O(n^2)
# Space O(n^2)
# Using DP
class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = [[False for i in range(len(s))] for j in range(len(s))]
        maxlen = 1
        ans = s[0:1]
        for j in range(len(s)):
            for i in range(j, -1, -1):
                if s[i] == s[j] and (j-i < 2 or dp[i+1][j-1]):
                    dp[i][j] = True
                    if j - i + 1 > maxlen:
                        maxlen = j - i + 1
                        ans = s[i:j+1]
        return ans

"""
opt[i, j] = true if the substring si,.......,sj is a palindrome

base case:
opt[i, i] = true
opt[i, i+1] = (si == sj)

j-i < 2 covers both base cases ie. when j-i == 0 and when j-i == 1
"""
