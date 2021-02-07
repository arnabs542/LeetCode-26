// Tags: Amazon BFS
// Failed Attempt, passed 81/84 testcases
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size(), inf = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, inf));
        dp[0][0] = 1;
        for (int i = 1; i < n && grid[0][i] == 0; ++i)
            dp[0][i] = dp[0][i - 1] + 1;
        for (int i = 1; i < n && grid[i][0] == 0; ++i)
            dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int t = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                    dp[i][j] = (t == inf) ? inf : t + 1;
                }
            }
        }
        return dp[n - 1][n - 1] == inf ? -1 : dp[n - 1][n - 1];
    }
};

/*
Can't use dp, doesn't satisfy optimal substructure property
A cell can be reached from 8 other adjacent cells but all those
8 paths are not available to us at an iteration of DP.
[0,0,1,0,0,0,0],
[0,1,0,0,0,0,1],
[0,0,1,0,1,0,0],
[0,0,0,1,1,1,0],
[1,0,0,1,1,0,0],
[1,1,1,1,1,0,1],
[0,0,1,0,0,0,0]
*/



// Unfortunately, using dfs we'd have to try every possible path to the end.
// We'd have to mark a cell as unvisited after recurring the neighbors (after the for-loop).
// But doing this, the problem would lead to TLE.
// For this reason, BFS is the best choice here



// Time:  O(n^2)
// Space: O(n)
// BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        int n = grid.size();
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            ++steps;
            
            // queue<pair<int, int>> q1;
            // or while (!q.empty())
            while (sz > 0) {
                // decrementing at start because it could directly
                // move to the next iteration after continue;
                --sz;
                auto [x, y] = q.front(); q.pop();
                
                // grid[0][0] could be 1, therefore using exchange
                // instead of a direct assignment
                if(exchange(grid[x][y], 1) == 1)
                    continue;
                
                if (x == n - 1 && y == n - 1)
                    return steps;
                
                // for (auto i = -1; i < 2; ++i)
                //     for (auto j = -1; j < 2; ++j)
                //         if (i != 0 || j != 0)
                for (int i = x - 1; i <= x + 1; ++i)
                    for (int j = y - 1; j <= y + 1; ++j)
                        if (i != x || j != y)
                            if (i >= 0 && j >= 0 && i < n && j < n && !grid[i][j])
                                q.push({i, j}); // or q1.push({i, j});
            }
            // or swap(q, q1);
        }
        return -1;
    }
};
