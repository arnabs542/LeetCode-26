// Tags: Memoization DFS Topological-sort Top-interview
// Time: O(m*n)
// Space: O(m*n)
// Using dfs + memoization
class Solution {
    vector<pair<int, int>> directions {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};

    // returns the longest distance starting from matrix[i][j]
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j) {
        if (memo[i][j] != 0)
            return memo[i][j];
        int maxLen = 0;
        for (auto &d: directions) {
            int ni = i + d.first;
            int nj = j + d.second;
            if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size() || matrix[ni][nj] <= matrix[i][j])
                continue;
            maxLen = max(maxLen, dfs(matrix, memo, ni, nj));
        }
        memo[i][j] = ++maxLen;
        return maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n));
        int res = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res = max(res, dfs(matrix, memo, i, j));
        return res;
    }
};

/*
1. Do DFS from every cell
2. Compare every 4 direction and skip cells that are out of boundary or smaller
3. Get matrix max from every cell's max
4. Use matrix[x][y] <= matrix[i][j] so we don't need a visited[m][n] array
5. The key is to cache the distance because it's highly possible to revisit a cell

Time Complexity:
each cell can be accessed 5 times at most: 4 times from the top, bottom, left and
right and one time from the outermost double for loop. 4 of these 5 visits 
will be look-ups except for the first one
*/




// Time:  O(m * n)
// Space: O(m * n)
// Using topological sort
class Solution {
    vector<pair<int, int>> directions {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // corner cases
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        // indegree[i][j] indicates the number of adjacent cells bigger than matrix[i][j]
        vector<vector<int>> indegree(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (auto &d : directions) {
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if (ni < 0 || nj < 0 || ni >= matrix.size() || nj >= matrix[0].size() || matrix[ni][nj] <= matrix[i][j])
                    continue;
                    ++indegree[ni][nj];
                }
        
        // Add each cell with indegree zero to the queue
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (indegree[i][j] == 0)
                    q.push({i, j});
        
        int len = 0;
        // BFS implements topological sort
        while (!q.empty()) {
            int sz = q.size();
            // all nodes in a level
            while (sz > 0) {
                auto [x, y] = q.front(); q.pop();
                for (auto &d: directions) {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && matrix[nx][ny] > matrix[x][y] && --indegree[nx][ny] == 0) {
                        q.push({nx, ny});
                    }
                }
                --sz;
            }
            ++len;
        }
        return len;
    }
};

/*
We regard
    * a cell in the matrix as a node,
    * a directed edge from node x to node y if x and y are adjacent 
    and x's value < y's value

No cycles can exist in the graph, i.e. a DAG is formed.

The problem becomes to get the longest path in the DAG.
*/
