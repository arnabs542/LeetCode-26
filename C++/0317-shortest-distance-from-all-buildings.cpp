// Tags: BFS Premium C3.ai
// Time: O(k * m * n), k is the number of the buildings
// Space: O(m * n)
class Solution {
    // update distance of empty lands reachable from the building at (x, y)
    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dists, vector<vector<int>>& cnts) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        const vector<pair<int, int>> directions {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        vector<pair<int, int>> cur_level {{x, y}}, next_level;
        visited[x][y] = true;
        int dist = 0;
        while (!cur_level.empty()) {
            ++dist;
            next_level.clear();
            for (auto& p : cur_level) {
                int i, j;
                tie(i, j) = p;
                for (auto& d : directions) {
                    int ni = i + d.first, nj = j + d.second;
                    if (0 <= ni && ni < m && 0 <= nj && nj < n && grid[ni][nj] == 0 && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        // add distance from the building at (x, y)
                        dists[ni][nj] += dist;
                        // this point is reachable from the building at (x, y)
                        ++cnts[ni][nj];
                        next_level.push_back({ni, nj});
                    }
                }
            }
            swap(cur_level, next_level);
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // number of buildings
        int cnt = 0;
        // sum of distances from all buildings to a point
        vector<vector<int>> dists(m, vector<int>(n));
        // number of buildings reachable from a point
        vector<vector<int>> cnts(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                    bfs(grid, i, j, dists, cnts);
                }
            }
        }
        // shortest sum of distances from all buildings to an empty land
        int shortest = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // empty land, shorter, reachable from all buildings
                if (grid[i][j] == 0 && dists[i][j] < shortest && cnts[i][j] == cnt)  {
                    shortest = dists[i][j];
                }
            }
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};



/*
To do: Faster approach
If we don't take a fresh "visited" for each BFS. 
Instead, if we walk only onto the cells that were reachable from all previous buildings, we
can speed up.
From the first building we only walk onto cells where grid is 0, and make them -1.
From the second building we only walk onto cells where grid is -1, and we make them -2. And so on.
*/
