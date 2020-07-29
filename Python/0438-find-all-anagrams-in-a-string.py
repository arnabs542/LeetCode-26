# Time:  O(n)
# Space: O(1)

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = []
        counter = collections.Counter(p)
        left = 0
        for right in range(len(s)):
            counter[s[right]] -= 1

            while left <= right and counter[s[right]] < 0:
                # if illegal char
                # restore/undo the subtracted count
                counter[s[left]] += 1
                left += 1
                # when exit left = right + 1

            if right - left + 1 == len(p):
                result.append(left)

        return result

# Notes:
# counter could also be implemented as:
# cnts = [0] * 26
# for c in p:
#     cnts[ord(c) - ord('a')] += 1
