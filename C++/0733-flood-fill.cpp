// Tage: Amazon
// Time:  O(m * n)
// Space: O(m * n)
// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int orig = image[sr][sc];
        if (orig == newColor)
            return image;

        using T = pair<int, int>;
        queue<T> q;
        q.emplace(sr, sc);
        vector<T> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            image[i][j] = newColor;
            for (const auto d: directions) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (ni < 0 || ni >= image.size() || nj < 0 || nj >= image[0].size())
                    continue;
                if (image[ni][nj] == orig)
                    q.emplace(ni, nj);
            }
        }
        return image;
    }
};
/*
i/p:
 [1,1,1],
 [1,1,0],
 [1,0,1]

o/p:
  [2,2,2],
  [2,2,0],
  [2,0,1]
*/
