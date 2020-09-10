# Time: O(n)
# Space: O(k)
class Solution:
    def minWindow(self, s: str, t: str) -> str:

        current_count = [0 for i in range(58)]
        expected_count = [0 for i in range(58)]
        #0 to 25: a to z and -32 to -7: A to Z

        for char in t:
            expected_count[ord(char)-ord('a')] += 1

        left, count, min_start, min_width = 0, 0, 0, float("inf")

        for right in range(len(s)):
            current_count[ord(s[right])-ord('a')] += 1

            if current_count[ord(s[right])-ord('a')] <= expected_count[ord(s[right])-ord('a')]:
                # counting the number of element of t observed so far
                count += 1

            if count == len(t):
                # all elements of t are observed
                while expected_count[ord(s[left])-ord('a')] == 0 or current_count[ord(s[left])-ord('a')] > expected_count[ord(s[left])-ord('a')]:
                    # filter unrequired elements
                    current_count[ord(s[left])-ord('a')] -= 1
                    left += 1

                if right-left+1 < min_width:
                    min_width = right-left+1
                    min_start = left


        if min_width == float("inf"):
            return ""

        return s[min_start:min_start + min_width]
