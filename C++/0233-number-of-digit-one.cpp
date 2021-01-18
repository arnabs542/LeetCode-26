// Tags: Math Amazon
// Time: O(logn) i.e. the number of digits (base 10 ~ any base)
// (every step we divide by 10)
// Space: O(1)
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m = m*10) {
            int a = n/m, b = n%m;
            // number of full streaks of m numbers
            ones += (a + 8) / 10 * m;
            // partial streak of b + 1 numbers
            ones += (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};
// Check notes
/*
Go through the digit positions by using position multiplier m 
with values 1, 10, 100, 1000, etc.

For each position, split the decimal representation into two parts
a & b

Make the case distincton between the current digit/position being
0, 1 and >=2.
*/
