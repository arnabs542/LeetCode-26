# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(no, nc, curr):
            if len(prev) == 2*n:
                result.append(curr)
                return
            if no < n:
                dfs(no+1, nc, curr + '(')
            if nc < no:
                dfs(no, nc+1, curr + ')')

        if n==0:
            return []
        result = []
        dfs(0,0,"")
        return result


# Notes:
# We can start an opening bracket if we still have one (of n)
# left to place. And we can start a closing bracket if it would
# not exceed the number of opening brackets.
