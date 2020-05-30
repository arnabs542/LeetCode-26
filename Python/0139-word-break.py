# Time:  O(n * l), l is the max length of the words.
# Space: O(n)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        max_len = 0
        for string in wordDict:
            max_len = max(max_len, len(string))

        can_break = [False for _ in range(n + 1)]
        can_break[0] = True

        for i in range(1, n + 1):
            for l in range(1, min(i, max_len) + 1):
                if can_break[i-l] and s[i-l:i] in wordDict:
                    can_break[i] = True
                    break

        return can_break[-1]

# Notes:
# It should have been s[i-l+1:i+1]. But we changed to s[i-l:i] as our
# string array starts from index 0
