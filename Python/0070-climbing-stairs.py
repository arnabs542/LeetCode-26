# Time:  O(n)
# Space: O(1)

class Solution:
    def climbStairs(self, n: int) -> int:
        # base case
        prev, current = 0, 1
        # runs n times
        for i in range(n):
            prev, current = current, prev + current

        return current
