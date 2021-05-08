// Tags: Array DP Google
// Time: O(m*n)
// Space: O(m*n) or O(1) if we reuse the matrix
// Reusing 0221-maximal-square
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i > 0 && j > 0 && matrix[i][j] == 1)
                    matrix[i][j] = min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]}) + 1;
                res += matrix[i][j];
           }
        }
        return res;
    }
};
/*
dp[i][j] = number of square that can be formed having matrix[i][j] at the bottom right corner.
(equivalent to the side of the biggest square that can be formed with matrix[i][j] as the
bottom right corner).

dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1 if matrix[i][j] = 1
           else
           0
Base case:
dp[i][0] = matrix[i][j]
dp[0][j] = matrix[i][j]

result is the sum of all values in dp matrix.
*/