// Tags: Bit-manipulation Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1:
        uint32_t diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // or diff &= (-diff);
        diff &= ~(diff - 1);

        // Pass 2:
        vector<int> res {0, 0}; // stores the two numbers we will return
        for (int num : nums) {
            if (diff & num) {
                // the bit is set
                res[0] ^= num;
            } else {
                // the bit is not set
                res[1] ^= num;
            }
        }
        return res;
    }
};
/*
1. In the first pass, we XOR all elements in the array, and 
   get the XOR of the two numbers we need to find.
   (Note that since two numbers are distinct, here only the bits where
   the two number differ will be set.)
   So find out an arbitrary set bit (for example, rightmost set bit)

2. In the second pass, we divide all numbers into two groups, one with
   the aforementioned bit set, another with aforementioned bit unset.
   => Two different numbers we need to find must fall into two distinct
      groups.
*/
