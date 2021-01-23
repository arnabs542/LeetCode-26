// Tags: BFS DP Amazon
// Time: O(m*n)
// Space: O(m*n)
// Bfs solution
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                } else {
                    // reset distances to infinity
                    // (just like Dijkstra algorithm)
                    matrix[i][j] = numeric_limits<int>::max();
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (const auto& d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr < 0 || nr >= matrix.size() || nc < 0 || nc >= matrix[0].size())
                    continue;
                // already lesser distance path available
                // (just like Dijkstra algorithm)
                if (matrix[nr][nc] <= matrix[r][c] + 1)
                    continue;
                // update distance
                matrix[nr][nc] = matrix[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return matrix;
    }
};



// Time: O(m*n)
// Space: O(m*n)
// Dp solution
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int inf = numeric_limits<int>::max();
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, inf));
        // top-left: top to bottom, left to right
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    // distance from upper cell
                    if (i > 0 && dp[i - 1][j] != inf)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    // distance from left cell
                    if (j > 0 && dp[i][j - 1] != inf)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        // bottom-right: bottom to up, right to left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    // distance from lower cell
                    if (i < m - 1 && dp[i + 1][j] != inf)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    // distance from right cell
                    if (j < n - 1 && dp[i][j + 1] != inf)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
        return dp;
    }
};
/*
We iterative twice (once from top-left and once from bottom-right) because if
we move only in one direction say top-left, the down and right cell aren't updated yet and 
there might be better paths beneath them which aren't also not updated yet.

First Run: cells have best top-left paths
Second Run: cells are now additionally aware of best bottom- right paths and choose the
            one with smallest distance

We need both to have best paths from all directions!
*/
