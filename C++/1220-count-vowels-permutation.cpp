// Tags: DP C3.ai
// Time: O(n*5)
// Space: O(n*5)
// Same dp template as 0309-best-time-to-buy-and-sell-stock-with-cooldown
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n + 1, vector<long>(5));
        const int MOD = 1e9 + 7;
        // one char string "a", "e", "i", "o", "u"
        for (int i = 0; i < 5; ++i)
            dp[1][i] = 1;
        for (int x = 2; x <= n; ++x) {
            // ending with 'a' : ending with 'e', 'i', 'u'
            dp[x][0] = (dp[x - 1][1] + dp[x - 1][2] + dp[x - 1][4]) % MOD;
            // ending with 'e' : ending with 'a', 'i'
            dp[x][1] = (dp[x - 1][0] + dp[x - 1][2]) % MOD;
            // ending with 'i' : ending with 'e', 'o'
            dp[x][2] = (dp[x - 1][1] + dp[x - 1][3]) % MOD;
            // ending with 'o' : ending with 'i'
            dp[x][3] = dp[x - 1][2] % MOD;
            // ending with 'u' : ending with 'i', 'o'
            dp[x][4] = (dp[x - 1][2] + dp[x - 1][3]) % MOD;
        }
        int res = 0;
        for (int i = 0; i < 5; ++i)
            res = (res + dp[n][i]) % MOD;
        return res;
    }
};
/*
dp[x][c] = number of strings of length x which end with char c

Base case:
dp[1][c] = 1 for 0 <= c <= 4

Check graph in notes (look at incoming edges to each char)
*/

// To do: Knight dialer approach
