// Tags: DFS DP WC221
// Time: O(m*n)
// Space: O(1), not including output array
// Since at each cell, we have just one choice for the next cell
// to go to, there is no backtracking and we can have a simpler
// iterative solution.
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // j -> index of the column from where ball is dropped
        // res[j] -> index of the column from where ball falls out
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; ++i) {
            // current col (initialized to i)
            int c = i;
            for (int r = 0; r < m; ++r) {
                // next col to check in same row
                int cn = c + grid[r][c];
                if (cn < 0 || cn >= n || grid[r][c] != grid[r][cn]) {
                    // return -1 if values don't match or we hit a wall
                    c = -1;
                    break;
                }
                // if grid[r][c] we go to diagonal right
                // else we go to diagonal left
                c = cn;
            }
            res.push_back(c);
        }
        return res;
    }
};



// Time: O(m*n), each ball travel across the column ie m 
// and we drop n balls.
// Space: O(m), due to recursion
// Dfs solution
class Solution {
    int dfs(vector<vector<int>> &grid, int r, int c) {
        // grid.size() not grid.size() - 1
        if (r == grid.size())
            return c;
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
            if (grid[r][c] == 1 && c < grid[0].size() - 1 && grid[r][c + 1] == 1)
                return dfs(grid, r + 1, c + 1);
            else if (grid[r][c] == -1 && c > 0 && grid[r][c - 1] == -1)
                return dfs(grid, r + 1, c - 1);
        }
        return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
        // j -> index of the column from where ball is dropped
        // res[j] -> index of the column from where ball falls out
        for (int j = 0; j < grid[0].size(); ++j)
            res[j] = dfs(grid, 0, j);
        return res;
    }
};

/*
If current grid grid[r][c] is a \ then check it's right column 
-> grid[r][c+1] is same or not and Go to it's digonal place 
-> grid[r+1][c+1] else return -1 from there

and if it is / then check it's left column grid[r][c-1] is same or 
not if it same then go 
-> grid[r+1][c-1] else return -1 from there

If You reach last Row return Column Number .

Do this task for each column.

Note: We can say it is not Dfs as at every cell we have just 1 choice
for the next cell to go to. (Each cell if either 1 or -1)
*/

// To do: DP solution
