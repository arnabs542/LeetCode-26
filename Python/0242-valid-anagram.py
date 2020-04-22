# Time O(nlogn)
# Space O(n)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)




# Time O(n)
# Space O(n)
import collections
class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        count = collections.defaultdict(int)
        # default value is 0
        for c in s:
            count[c] += 1
        for c in t:
            count[c] -= 1
            if count[c] < 0:
                return False

        return True



# Time O(n)
# Space O(n)
import collections
class Solution3:
    def isAnagram(self, s: str, t: str) -> bool:
        return collections.Counter(s) == collections.Counter(t)
