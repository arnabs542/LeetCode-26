// Tags: Amazon Union-find DFS
// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), count = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }  
            }
        }
        for (int i = 0; i < n; ++i)
            if (visited[i] == 0) {
                dfs(adj, i, visited);
                ++count;
            }  
        return count;
    }

    void dfs(vector<vector<int>> &adj, int u, vector<int> &visited) {
        if (visited[u] == 1)
            return;
        visited[u] = 1;
        for (auto v: adj[u]) {
            dfs(adj, v, visited);
        }
    }
};



// Time: O(n^2)
// Space: O(n), matrix M already behaves as an adjacency list
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), count = 0;
        vector<int> visited(n);
        for (int i = 0; i < n; ++i)
            if (visited[i] == 0) {
                // visited[i] = 1
                dfs(M, i, visited);
                ++count;
            }  
        return count;
    }

    void dfs(vector<vector<int>> &M, int i, vector<int> &visited) {
        for (int j = 0; j < M.size(); ++j) {
            if (j == i)
                continue;
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, j, visited);
            }
        }
    }
};



// Time:  O(n^2)
// Space: O(n)
class UnionFind {
    vector<int> parent;
    vector<int> size;
public:
    int count;
    UnionFind (int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
        // all nodes are disjoint initially
        // making n disconnected graphs
        count = n;
    }

    int Find(int x) {
        // topmost root
        if (x == parent[x])
            return x;
        // find root of root and perform path compression
        return parent[x] = Find(parent[x]);
    }
    
    bool Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu == pv)
            return false;
        if (size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        // With each union, we join two disconnected graphs
        // and therefore count decrements by 1 
        --count;
        return true;
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), count = 0;
        UnionFind uf(n);
        for (int i = 0;  i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (M[i][j] == 1)
                    uf.Union(i, j);
        // number of disconnected graphs
        return uf.count;
    }
};
