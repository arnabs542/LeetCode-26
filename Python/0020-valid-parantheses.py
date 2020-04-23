# Time O(n)
# Space O(n)
class Solution:
    def isValid(self, s: str) -> bool:
        # dictionary different keys from cpp solution
        stack, lookup = [], {'(':')', '{':'}', '[':']'}

        for c in s:
            if c in lookup:
                # opening bracket
                stack.append(c)
            elif len(stack) == 0 or lookup[stack.pop()] != c:
                #if closing bracket
                return False

        return len(stack)==0
