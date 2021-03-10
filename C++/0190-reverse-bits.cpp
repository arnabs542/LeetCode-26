// Time: O(1)
// Space: O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = n;
        int s = 31; // extra shift needed at end
        for (n >>= 1; n; n >>= 1) {
            r <<= 1;
            r |= n & 1;
            --s;
        }
        r <<= s; // shift when n's highest bits are zero
        return r;
    }
};
