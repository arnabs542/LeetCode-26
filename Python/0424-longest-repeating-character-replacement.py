# Time O(n)
# Space O(1)
import collections
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, result = 0, 0
        maxCount = 0
        count = collections.Counter()

        for right in range(len(s)):
            count[s[right]]+=1
            # max count encountered so far
            maxCount = max(maxCount, count[s[right]])
            # should have been count.most_common(1)[0][1]
            # i.e. current max count but O(n)

            # if current length ie right - left + 1 is
            # greater than maxCount so far + k, move left
            while (right - left + 1 - maxCount > k):
                count[s[left]]-=1
                left+=1
            # pointers have been correct, so capture result
            result = max(result, right - left + 1)
        return result

# Notes:
# Since we are only interested in the longest valid substring,
# our sliding windows need not shrink, even if a window may cover
# an invalid substring. We either grow the window by appending
# one char on the right, or shift the whole window to the right
# by one. And we only grow the window when the count of the new
# char exceeds the historical max count (from a previous window
# that covers a valid substring).
#
# That is, we do not need the accurate max count of the current
# window; we only care if the max count exceeds the historical
# max count; and that can only happen because of the new char.
