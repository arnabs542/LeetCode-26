// Tags: Backtracking Google
// Time: O(k * 3^k), where k = number of cells containing gold.
//       (We perform analysis for k cells, and from each cell we can go in atmost 3 directions)
// Space: O(k)
class Solution {
    // return the maximum gold path starting from (i, j)
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
           grid[i][j] <= 0) // skip visited or 0 value cells
            return 0;
        // mark this cell visited
        grid[i][j] = -grid[i][j];
        // atleast one of the adjacent cells will be skipped
        int res = max({dfs(grid, i + 1, j), dfs(grid, i - 1, j), dfs(grid, i, j + 1),
                      dfs(grid, i, j - 1)});
        // return to original value
        grid[i][j] = -grid[i][j];
        return res + grid[i][j];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
/*
Since we have no more than 25 cells with gold, a straightforward Dfs should do.
*/
