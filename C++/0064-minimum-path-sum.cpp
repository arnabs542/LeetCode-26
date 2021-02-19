// Tags: Array DP Amazon
// Time: O(m*n)
// Space: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = dp[j - 1] + grid[0][j];
        
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
/*
dp[i][j] = minimum path sum from 0,0 to i,j
dp[i, j] = min(dp[i - 1, j], dp[i, j - 1]) + grid[i][j]

Base Case:
dp[0][j] = dp[0][j - 1] + grid[0][j]
dp[i][0] = dp[i - 1][0] + grid[i][0]

Dijkstra's not required as we only move either down or right.
*/
