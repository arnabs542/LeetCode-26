// Tags: Graph DFS Amazon Premium
// Time: O(n + e)
// Space: O(n + e)
// DFS finding cycle
class Solution {
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int u, int destination) {
        if (adj[u].empty())
            return u == destination;
        if (visited[u] == -1)
            return false;
        if (visited[u] == 1)
            return true;
        visited[u] = -1;
        for (auto v : adj[u]) {
            if (!dfs(adj, visited, v, destination))
                return false;
        }
        visited[u] = 1;
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n);
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        return dfs(adj, visited, source, destination);
    }
};

/*
If a path exists from the source node to a node with no outgoing
edges, then that node must be equal to destination. Here, we simply
need to see that if a node does not have any neighbors in the
adjacency list structure, then it has to be the destination or else
we return false

The number of possible paths from source to destination is a finite
number. This simply means that the graph is actually a tree. 
Or in other words, there are no cycles in the graph
*/
