// Tags: WC212 Binary search Graph
// Failed attempt: stack-overflow as graph as cycles which causes
// recursive call to already visited ancestor node
// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int res = numeric_limits<int>::max();
//         dfs(0, 0, res, numeric_limits<int>::min(), heights);
//         return res;
//     }
//
//     void dfs(int i, int j, int &res, int cost, vector<vector<int>>& heights) {
//         if (i == heights.size() - 1 && j == heights[0].size() - 1) {
//             res = min(res, cost);
//             return;
//         }
//
//         if (i != heights.size() - 1)
//             dfs(i + 1, j, res, max(cost, heights[i+1][j] - heights[i][j]), heights);
//         if (i != 0)
//             dfs(i - 1, j, res, max(cost, heights[i-1][j] - heights[i][j]), heights);
//
//         if (j != heights[0].size() - 1)
//             dfs(i, j + 1, res, max(cost, heights[i][j+1] - heights[i][j]), heights);
//         if (j != 0)
//             dfs(i, j - 1, res, max(cost, heights[i][j-1] - heights[i][j]), heights);
//     }
// };

// Time:  O(m * n * log(m * n))
// Space: O(m * n)
// Dijkstra algorithm solution
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
        // effort, i, j
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, 0, 0);

        while(!min_heap.empty()) {
            const auto [cost, i, j] = min_heap.top(); min_heap.pop();
            if (i == m - 1 && j == n - 1)
                return cost;
            for (const auto &[di, dj]: directions) {
                int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < m && 0 <= nj && nj < n))
                    continue;
                int ncost = max(cost, abs(heights[ni][nj] - heights[i][j]));
                if (ncost < dist[ni][nj]) {
                    dist[ni][nj] = ncost;
                    min_heap.emplace(ncost, ni, nj);
                }
            }
        }
        return -1;
    }
};

/*
Unlike prob 0787-cheapest-flights-within-k-stops, we shouldn't put multiple
copies of same node in heap, as it will lead to TLE.

Like regular shortest path problem, we do decrease key i.e only put new effort
if it is less than previous effort to ni, nj
*/

// To do: Bellmann ford & Binary search-BFS solution
