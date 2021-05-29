// Tags: BFS Google
// Time: O(m*n)
// Space: O(m*n)
// Somewhat similar to 0909-snakes-and-ladders
// Bfs + Dfs
class Solution {
    // right, left, down, up
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int r, int c, vector<vector<int>>& grid, queue<pair<int, int>>& q,
        vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c])
            return;
        visited[r][c] = true;
        int next = grid[r][c] - 1;
        q.push({r, c});
        dfs(r + dir[next][0], c + dir[next][1], grid, q, visited);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        dfs(0, 0, grid, q, visited);
        int cost = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [r, c] = q.front(); q.pop();
                if (r == m - 1 && c == n - 1)
                    return cost;
                for (int d = 0; d < 4; ++d) {
                    // change direction,
                    // then call dfs going as far as you can (greedily explore)
                    dfs(r + dir[d][0], c + dir[d][1], grid, q, visited);
                }
            }
            ++cost;
        }
        return -1;
    }
};
/*
1. Find out all reachable nodes without changing anything (dfs).
2. Push all visited nodes to the queue.
3. Now pop from queue:
    a. For each node, try changing it to all 3 other directions
       (some of which will be ignored as already visited on current or previous levels)
    b. Call dfs, pushing all new reachable and unvisited nodes to the queue.
    c. and Repeat.
*/
