# Time:  O(4^n)
# Space: O(n)
# Recursive Solution
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        self.lookup = { '2':['a', 'b', 'c'], '3':['d', 'e', 'f'], '4':['g', 'h', 'i'], '5':['j', 'k', 'l'] , '6':['m', 'n', 'o'], '7':['p', 'q', 'r', 's'], '8':['t', 'u', 'v'], '9':['w', 'x', 'y', 'z']}
        self.result = []
        self.helper(0, "", digits)
        return self.result

    def helper(self, cur, ans, digits):
        if cur == len(digits):
            self.result.append(ans)
            return

        for c in self.lookup[digits[cur]]:
            self.helper(cur+1, ans + c, digits)
