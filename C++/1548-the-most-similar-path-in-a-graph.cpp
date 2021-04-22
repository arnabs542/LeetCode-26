// Tags: DP Graph Google Premium
// Time: O(n^2 * m), m is the length of targetPath
// Space: O(n * m)
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> adj(n);
        for (auto road: roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        int m = targetPath.size();
        vector<vector<int>> dp(m, vector<int>(n, m));
        // previous node to path for targetPath[:i] ending with node v
        vector<vector<int>> prev(m, vector<int>(n, 0));
        
        // i in dp array is 0 indexed
        for (int v = 0; v < n; ++v)
            dp[0][v] = (names[v] != targetPath[0]);
        
        for (int i = 1; i < m; ++i) {
            for (int v = 0; v < n; ++v) {
                for (int u : adj[v]) {
                    if (dp[i - 1][u] < dp[i][v]) {
                        dp[i][v] = dp[i - 1][u];
                        prev[i][v] = u;
                    }
                }
                dp[i][v] += (names[v] != targetPath[i]);
            }
        }
        vector<int> res {0};
        int min_dist = m;
        for (int v = 0; v < n; ++v) {
            if (dp[m - 1][v] < min_dist) {
                min_dist = dp[m - 1][v];
                res.back() = v;
            }
        }
        for (int i = m - 1; i > 0; --i) {
            int u = prev[i][res.back()];
            res.push_back(u);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
Let's first calculate the minimum edit distance without worrying about the path.

dp[i][v] = minimum edit distance for targetPath[:i+1] ending with city v.

dp[i][v] = min(dp[i - 1][u] + targetPath[i] != names[v]) for all edges (u, v)

=> result = min(dp[n][u] for u in range(n))

Base case:
dp[0][v] = names[v] != targetPath[0]


To construct the optimal path, we can maintain a 2D array (or dict) prev when populating
dp array. 
Suppose prev[i][v] is u, then (u, v) is the ending edge of the optimal path at dp[i][v].
*/
