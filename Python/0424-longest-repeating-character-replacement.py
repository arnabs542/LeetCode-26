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
            maxCount = max(maxCount, count[s[right]])

            while (right - left + 1 - maxCount > k):
                count[s[left]]-=1
                left+=1

            result = max(result, right - left + 1)
        return result
