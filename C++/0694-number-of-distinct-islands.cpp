// Tags: Amazon DFS Hash-table
// Time:  O(m * n)
// Space: O(m * n)
// Simpler solution
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> s;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    string path;
                    helper(grid, i, j, path, 'o');
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
    
    void helper(vector<vector<int>> &grid, int i, int j, string &path, char dir) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j])
            return;
        grid[i][j] = 0;
        path.push_back(dir);
        helper(grid, i + 1, j, path, 'd');
        helper(grid, i - 1, j, path, 'u');
        helper(grid, i, j + 1, path, 'r');
        helper(grid, i, j - 1, path, 'l');
        path.push_back('b');
    }
};
/*
{1, 1, 0},
{1, 0, 0},
{0, 0, 0},
{1, 1, 0},
{0, 1, 0}

First shape: odbrbb
Last shape: ordbbb

If we dont use a "b" for our backtracking step, 
we will end up considering both the above islands as 1, whereas they are different.
*/



// Time:  O(m * n)
// Space: O(m * n)
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                string island;
                if (dfs(i, j, &grid, &island)) {
                    islands.emplace(island);
                }
            }
        }
        return islands.size();
    }

private:
    bool dfs(const int i, const int j,
             vector<vector<int>> *grid, string *island) {
        
        static const unordered_map<char, pair<int, int>>
            directions = { {'l', {-1,  0} }, {'r', { 1,  0} },
                           {'u', { 0,  1} }, {'d', { 0, -1} }};

        if (i < 0 || i >= grid->size() ||
            j < 0 || j >= (*grid)[0].size() ||
            (*grid)[i][j] <= 0) {
            return false;
        }
        (*grid)[i][j] *= -1;
        for (const auto& kvp : directions) {
            island->push_back(kvp.first);
            dfs(i + kvp.second.first, j + kvp.second.second, grid, island);
        }
        return true;
    }
};

/*
11011
10000
00001
11011

First shape: ddurlurdurll
Last shape: ddurldurlurl
*/
