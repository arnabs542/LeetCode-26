# Time:  O(n)
# Space: O(1)

class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 0 or s[0] == '0':
            return 0
        prev, prev_prev = 1, 1

        for i in range(1, len(s)):
            cur = 0
            if s[i] != '0':
                cur = prev
            if s[i - 1] == '1' or (s[i - 1] == '2' and s[i] <= '6'):
                cur += prev_prev
            prev, prev_prev = cur, prev

        return prev

        
