// Tags: DP Google
// Time: O(n)
// Space: O(n)
// Also check 1690-stone-game-vii
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // initial value can't be 0 as atleast one stone must be picked
        // if all 3 choices give negative score gains
        vector<int> dp(n, -1e9);
        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
            }
        }
        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};
/*
dp[i] = maximum score the first player can gain over the second player if he/she
play on A[i:]

dp[i] = max(sum(A[i : i + k]), dp[i + k + 1])
        where 0 <= k <= 2
*/



// Time: O(n)
// Space: O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4);
        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            // reset value
            dp[i % 4] = -1e9;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                take += stoneValue[i + k];
                dp[i % 4] = max(dp[i % 4], take - (i + k + 1 < n ? dp[(i + k + 1) % 4] : 0));
            }
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};
/*
We only need three more results (dp[i + 1], dp[i + 2] and dp[i + 3]) in order to get the current result.
*/
