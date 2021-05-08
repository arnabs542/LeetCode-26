// Tags: Array DP Google
// Time: O(m*n)
// Space: O(m*n)
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0)
                    continue;
                // horizontal
                dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                // main diagonal
                dp[i][j][1] = (i > 0 && j > 0) ? dp[i - 1][j - 1][1] + 1 : 1;
                // vertical
                dp[i][j][2] = i > 0 ? dp[i - 1][j][2] + 1 : 1;
                // anti-diagonal
                dp[i][j][3] = (i > 0 && j < n - 1) ? dp[i - 1][j + 1][3] + 1 : 1;
                for (int d = 0; d < 4; ++d)
                    res = max(res, dp[i][j][d]);
            }
        }
        return res;
    }
};
/*
dp[i][j][d] = length of longest line of consecutive one ending at mat[i][j]
              in direction d, where,
              d = 0 means horizontal
              d = 1 means diagonal
              d = 2 means vertical
              d = 3 means anti-diagonal

Note that each cell of the dp table only depends on the current row or previous row 
so we can easily optimize the above algorithm to use only O(m) space using % 2
*/
