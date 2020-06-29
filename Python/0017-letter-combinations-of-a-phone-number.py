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


# Time:  O(4^n)
# Space: O(4^n)
# BFS Solution using two lists
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        mapping = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",\
                  "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        currlevel = ['']
        for d in digits:
            nextlevel = []
            for x in currlevel:
                for c in mapping[d]:
                    nextlevel.append(x + c)
            currlevel = nextlevel
        return currlevel


# Time:  O(4^n)
# Space: O(4^n)
# BFS Solution using queue
import collections
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        mapping = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",\
                  "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        queue = collections.deque([""])
        for i, d in enumerate(digits):
            # i represents no of chars in prev level
            while len(queue[0]) == i:
                x = queue.popleft()
                for c in mapping[d]:
                    queue.append(x + c)
        return queue
