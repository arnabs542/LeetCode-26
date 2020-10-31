// Time:  O(m * n)
// Space: O(m * n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<tuple<int, int, int>> q;

        // count of fresh oranges
        int count = 0;

        for (int r = 0; r < grid.size(); ++r)
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 2)
                    q.emplace(r, c, 0);
                else if (grid[r][c] == 1)
                    ++count;
            }

        int minutes = 0;
        while (!q.empty()) {
            int r, c;
            tie(r, c, minutes) = q.front(); q.pop();

            for (const auto &d: directions) {
                int nr = r + d.first, nc= c + d.second;

                if (!(0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size()))
                    continue;

                if (grid[nr][nc] == 1) {
                    --count;
                    grid[nr][nc] = 2;
                    q.emplace(nr, nc, minutes + 1);
                }
            }
        }
        return (count == 0) ? minutes: -1;
    }

};
