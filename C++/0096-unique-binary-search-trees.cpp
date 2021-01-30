// Tags: DP Tree Amazon
// Time: O(n^3)
// Space: O(n^2)
// DP solution
// Check Python version for comments
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



// Time:  O(n^2)
// Space: O(n)
// DP solution
// Check Python version for comments
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int l = 2; l <= n; ++l) {
            for (int left_l = 0; left_l < l; ++left_l) {
                dp[l] += dp[left_l]*dp[l - left_l - 1];
            }
        }
        return dp[n];
    }
};
