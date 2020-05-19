// Time O(m*n)
// Space O(m*n)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //if (grid.empty())
         //   return 0;
        int count = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count+=1;
                    dfs(grid, i, j);
                }
            }

        return count;
    }

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        //if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
       //     return;

        if (grid[x][y] == '0')
            return;

        grid[x][y] == '0';

        if (x != 0)
            dfs(grid, x-1, y);
        if (x != grid.size() - 1)
            dfs(grid, x+1, y);
        if (y != 0)
            dfs(grid, x, y-1);
        if (y != grid[0].size() - 1)
            dfs(grid, x, y+1);

    }
};
