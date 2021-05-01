// Tags: Google DFS
// Time: O(m*n)
// Space: O(1)
// Similar to 1020-number-of-enclaves
class Solution {
    // flood fill and return count of connected 0's
    int fill(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 1)
            return 0;
        grid[i][j] = 1;
        return 1 + fill(grid, i + 1, j) + fill(grid, i, j + 1) + fill(grid, i - 1, j)
            + fill(grid, i, j - 1);        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i * j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
                    fill(grid, i, j);
            }
        }
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                cnt += fill(grid, i, j) > 0;
            }
        }
        return cnt;
    }
};
/*
First we need to exclude connected group of 0s on the corners because they are not closed
island.
Then we can return number of connected component of 0s on the grid.
*/



// Time: O(m * n)
// Space: O(1)
// First attempt
class Solution {
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if (grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool closed = true;
        // even if one of the directions return false,
        // continue with the remaining directions
        if (!dfs(grid, i + 1, j))
            closed = false;
        if (!dfs(grid, i, j + 1))
            closed = false;
        if (!dfs(grid, i - 1, j))
            closed = false;
        if (!dfs(grid, i, j - 1))
            closed = false;
        return closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};
