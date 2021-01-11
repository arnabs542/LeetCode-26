// Tags: DFS BFS Union-find Floyd-warshall
// Time: O(e + n*(v + e*2)), build graph + n queries * (|V| + |E|)
// where e = no of equations, v = no of variables, n = no of queries
// Space: O(v^2)
// Dfs solution
class Solution {
    double dfs(string start, string end, unordered_map<string, unordered_map<string, double>> &adj, unordered_set<string> &visited) {
        // only for starting node
        if (!adj.count(start))
            return -1.0;
        if (adj[start].count(end))
            return adj[start][end];
        visited.insert(start);
        for (auto &kvp: adj[start]) {
            // if we put visited condition here, we don't have to
            // put it at the entry of function
            if (!visited.count(kvp.first)) {
                double productWeight = dfs(kvp.first, end, adj, visited);
                if (productWeight != -1.0)
                    return productWeight*kvp.second;
            }
        }
        // return extreme last node in a branch
        // (can't go back as ancestor nodes are already visited)
        // also cases like ["a", "a"] return from here as "a" is not
        // present in adj["a"]
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // or unordered_map<string, vector<pair<string, double>> adj
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u][v] = values[i];
            adj[v][u] = 1/values[i];
        }
        vector<double> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            unordered_set<string> visited;
            res[i] = dfs(queries[i][0], queries[i][1], adj, visited);
        }
        return res;
    }
};
/* for each query, even if the end node is present we may end up traversing
   the whole graph.
*/



// Time: O(e + n*(v + e*2)), build graph + n queries * (|V| + |E|)
// where e = no of equations, v = no of variables, n = no of queries
// Space: O(v^2)
// Bfs solution
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1/values[i]});
        }
        vector<double> res(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++i) {
            if (!adj.count(queries[i][0]) || !adj.count(queries[i][1])) {
                continue;
            }
            unordered_set<string> visited;
            queue<pair<string, double>> q;
            q.push({queries[i][0], 1.0});
            while (!q.empty()) {
                auto [u, w] = q.front(); q.pop();
                if (u == queries[i][1]) {
                    res[i] = w;
                    break;
                }
                visited.insert(u);
                for (auto &v: adj[u])
                    if (!visited.count(v.first))
                        q.push({v.first, w*v.second});
            }
        }
        return res;
    }
};
/* Again, for each query, we may end up traversing
   the whole graph.
*/
