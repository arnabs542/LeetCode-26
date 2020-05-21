# Time:  O(logn) = O(32)
# Space: O(1)
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n &= n-1
            count += 1
        return count

"""
Notes: Here we are using bit operation to cancel a 1 in each round.
Think of a number in binary n = XXXXXX1000, n - 1 is XXXXXX0111.
n & (n - 1) will be XXXXXX0000 which is just cancel the last 1

Using built in function : return bin(n).count('1')
"""
