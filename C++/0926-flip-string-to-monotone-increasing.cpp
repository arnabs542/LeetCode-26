// Tags: Array DP
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ones = 0, dp = 0;
        for (auto c : S) {
            if (c == '1')
                ++ones;
            else
                dp = min(dp + 1, ones);
        }
        return dp;
    }
};

/*
dp = minimum number of flips to make S [0......i] monotone
increasing.

if S[i] == 0
    dp = min(dp + 1, ones)
    i.e. (either flip newly appended 0 to 1 or flip 'ones' 1's
    in original string to 0)
else
    ones++;
    
where = ones denotes the number of 1's in the original string seen
        so far

Eg. 0101100011
flip count = 5
ones count = 4
ans = 3
*/
