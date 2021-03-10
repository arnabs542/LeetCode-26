// Tags: DP Bit-manipulation Amazon
// Time: O(n*k), k is the number of bits in x
// Space: O(n)
// Reusing 0191-number-of-1-bits



// Time: O(n)
// Space: O(n)
// Dp + least significant bit
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (int i = 1; i <= num; ++i)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};
/*
x =  1001011101
x' = 100101110
x' is differ than x by one bit, because x' can be considered as the result
of removing the least significant bit of x.

dp[x] = dp[x/2] + x % 2 (lsb set or unset)
*/



// Time: O(n)
// Space: O(n)
// Dp + last set bit
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (int i = 1; i <= num; ++i)
            dp[i] = dp[i & (i - 1)] + 1;
        return dp;
    }
};
/*
x =           101100
x & (x - 1) = 101000

dp[x] = dp[x & (x - 1)] + 1;

x & (x - 1) is same as x with last (rightmost) set bit zeroed.
*/
