# Time: O(26*n), each search takes O(n)
# Space: O(1), store l and r for 26 characters
class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        # c : (l, r)
        ranges = {c: (s.index(c), s.rindex(c)) for c in set(s)}

        def findrightvalid(i):
            right = ranges[s[i]][1]
            j = i
            while j <= right:
                if ranges[s[j]][0] < i:
                    # not valid substing
                    return -1
                right = max(right, ranges[s[j]][1])
                j += 1
            return right

        right = len(s)-1
        prev_sub = ""
        res = []
        # we can even sort l of each char
        for i in range(len(s)):
            if i == ranges[s[i]][0]:
                # first occurence
                new_right = findrightvalid(i)
                if new_right != -1:
                    if i > right:
                        res.append(prev_sub)
                    right = new_right
                    prev_sub = s[i:right+1]
        # last substring
        if prev_sub:
            res.append(prev_sub)
        return res
