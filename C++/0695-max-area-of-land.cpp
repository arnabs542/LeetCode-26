// Tags: DFS Amazon
// Time:  O(m * n)
// Space: O(m * n), the max depth of dfs may be m * n
class Solution {
    bool dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        static const vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0)
            return false;
        grid[i][j] = -1;
        ++area;
        for (const auto& d : directions)
            dfs(grid, i + d.first, j + d.second, area);
        return true;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int area = 0;
                if (dfs(grid, i, j, area))
                    res = max(res, area);
            }
        }
        return res;
    }
};
