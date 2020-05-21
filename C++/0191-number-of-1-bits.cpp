// Time:  O(logn) = O(32)
// Space: O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if (n & 1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};


/*
Notes:
Using built-in function: return __builtin_popcount(n);
*/
