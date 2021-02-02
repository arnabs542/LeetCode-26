// Tags: WC225 DP
// Time: O(m*n)
// Space: O(m*n)
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int x = i - 1 < 0 ? 0 : dp[i - 1][j];
                int y = j - 1 < 0 ? 0 : dp[i][j - 1];
                int z = i - 1 < 0 || j - 1 < 0 ? 0 : dp[i - 1][j - 1];
                dp[i][j] = x ^ y ^ matrix[i][j] ^ z;
                res.push_back(dp[i][j]);
            }
        }
        nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<int>());
        return res[k - 1];
    }
};
/*
dp[i][j] = XOR of all values in the rectange whole bottom right corner
lies at coordinate (i, j)
dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ matrix[i][j] ^ dp[i - 1][j - 1]

Since region represented by rectange cornered at (i - 1, j - 1) is included
twice, we have to subtract that.
(As a ^ b ^ a = b, ^ dp[i - 1][j - 1] behaves as - dp[i - 1][j - 1] if it
was normal sum of all values)
*/
