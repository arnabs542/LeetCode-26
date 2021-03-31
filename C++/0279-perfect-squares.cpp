// Tags: DP Amazon Math
// Time: O(n*sqrt(n)), for any target t, the number of perfect squares
//       <=t are sqrt(t)
// Space: O(n)
// Similar to 0322-coin-change O(k) space solution and 0377-combination-sum-iv
// (don't mind considering permutations)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int t = 1; t <= n; ++t) {
            int num = 1;
            while (num*num <= t) {
                dp[t] = min(dp[t], dp[t - num*num] + 1);
                ++num;
            }
        }
        return dp[n];
    }
};
/*
Say for target 13, we don't mind considering 4 + 9 and 9 + 4 twice as we
are taking minimum out of all those (not sum like in number of ways).

dp[t] = minimum number of perfect squares that add upto target t

dp[t] = min [1 <= num^2 <= t] dp[t - num^2] + 1
*/
