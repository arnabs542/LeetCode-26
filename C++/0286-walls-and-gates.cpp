// Tags: BFS Amazon Premium
// Time: O(m*n)
// Space: O(1)
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            
            // top
            if (row > 0 && rooms[row - 1][col] == INT_MAX) {
                rooms[row - 1][col] = rooms[row][col] + 1;
                q.push({row - 1, col});
            }
            
            // down
            if (row < m - 1 && rooms[row + 1][col] == INT_MAX) {
                rooms[row + 1][col] = rooms[row][col] + 1;
                q.push({row + 1, col});
            }
            
            // left
            if (col > 0 && rooms[row][col - 1] == INT_MAX) {
                rooms[row][col - 1] = rooms[row][col] + 1;
                q.push({row, col - 1});
            }
            
            // right
            while (col < n - 1 && rooms[row][col + 1] == INT_MAX) {
                rooms[row][col + 1] = rooms[row][col] + 1;
                q.push({row, col + 1});
            }
        }
    }
};

/* When we replace cell from INF to a lower integer value, we
   mark it visited. */
