// Tags: Amazon DFS
// Time:  O(|V| + |E|), dfs
// Space: O(|V| + |E|), adjacency list
// Tarjan's algorithm (finding bridges in a graph)
class Solution {
    int timer = 0;
    // entry time of each node
    vector<int> in;
    // (entry time of) lowest encestor that can be reached from node
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> res;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (const auto &c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        low.resize(n);
        visited.resize(n);
        in.resize(n);
        dfs(adj, 0, -1);
        return res;
    }

    void dfs(const vector<vector<int>> &adj, int u, int parent) {
        // mark it visited
        visited[u] = true;
        // initialize low and in values
        in[u] = low[u] = timer++;

        for (const auto &child: adj[u]) {
            if (child == parent)
                continue;
            if (visited[child]) {
                // edge u - child is a back edge
                // min because we don't to consider this edge again from other side
                // when we backtrack
                low[u] = min(low[u], in[child]);
            } else {
                // edge u - child is a forward edge
                dfs(adj, child, u);
                // indicates that child is not connected to an ancestor of u i.e. not making a cycle
                if (in[u] < low[child])
                    res.push_back({u, child});
                // if a child can reach an ancestor, current node can also reach ancestor via the child
                low[u] = min(low[u], low[child]);
            }
        }

    }
};
