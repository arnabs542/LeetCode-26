// Time: O(n^3)
// Space: O(n^2)
// DP solution.
class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Base case
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        
        // length including ith & jth element
        for (int l = 2; l <= n; ++l)
            for (int i = 0; i <= n - l; ++i) { // i can't be greater n - l
                int j = i + l - 1;
                for (int r = i; r <= j; ++r) {
                    if (r == i)
                        dp[i][j] += dp[r + 1][j];
                    else if (r == j)
                        dp[i][j] += dp[i][r - 1];
                    else
                        dp[i][j] += dp[i][r-1]*dp[r+1][j];
                }
            }
        return dp[0][n-1];
    }
};