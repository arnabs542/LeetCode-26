// Tags: DP Amazon
// Time: O(K*N^2)
// Space: O(N^2)
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        static const vector<pair<int, int>> directions {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        vector<vector<vector<double>>> dp(2, vector<vector<double>>(N, vector<double>(N)));
        dp[0][r][c] = 1.0;
        // if K = 0, result is 1.0
        double sum = 1.0;
        for (int step = 1; step <= K; ++step) {
            sum = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    // reset current step squares
                    dp[step % 2][i][j] = 0;
                    for (const auto& d: directions) {
                        int ni = i + d.first, nj = j + d.second;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N)
                            dp[step % 2][i][j] += dp[(step - 1) % 2][ni][nj]*0.125;
                    }
                    sum += dp[step % 2][i][j];
                }
            }
        }
        return sum;
    }
};
/*
After k moves, total possibilities = 8^k
Let dp[k][r][c] be probability of being on square (r, c) after exactly k steps.

dp[k][r][c] = sigma (x, y) over D, d[k - 1][r + x][c + y] * 1/8
              (this square can be reached from atmost 8 adjacent cells)

Base case:
dp[0][r][c] = 1

Sum all entries in dp[K][][] to get the final result.
*/

/*
Why not Bfs ?
At each square, knight has 8 possibilites for the next square to go to.
It can even come back to the same square again (unlike regular bfs, where
we avoid so my using a visited set). So, the total number of
paths are exponential O(8^(m*n)) and therefore Bfs will lead to TLE.
*/
