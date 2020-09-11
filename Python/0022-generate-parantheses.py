"""
Brute force: 2**2n sequences of '(' and ')', out of all check
how many are valid.
If the net number of opening brackets minus closing brackets
falls below zero at any time, or doesn't end in zero,
the sequence is invalid - otherwise it is valid.
"""

# Time:  O(4^n / n*3/2)): upper bound of Catalan number, 2nCn/n+1
# Space: O(n)
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(no, nc, curr):
            if len(curr) == 2*n:
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


"""
We can start an opening bracket if we still have one (of n)
left to place. And we can start a closing bracket if it would
not exceed the number of opening brackets.
"""
