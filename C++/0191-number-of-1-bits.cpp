// Time:  O(1), atmost 32 bits
// Space: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c;
        for (c = 0; n; n >>= 1) {
            c += n & 1;
        }
        return c;
    }
};



// Brian Kernigan's bit counting
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c;
        // only as many iterations as there are bits set
        for (c = 0; n; ++c) {
            // zeroing out the least significant nonzero bit
            n = n & (n - 1);
        }
        return c;
    }
};
/*
Notes:
Using built-in function: return __builtin_popcount(n);
*/
