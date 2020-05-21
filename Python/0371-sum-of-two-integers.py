# Time O(1)
# Space O(1)
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        if b == 0:
            return a

        while b:
            c = a & b
            a = (a ^ b) & mask
            b = (c << 1) & mask

        if (a >> 31) & 1:
            return ~(a ^ mask)
        else:
            return a

# Notes : ~(a ^ mask) is done to sign extend 32 bit negative int in 2's complement form to long int
