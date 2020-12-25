// Tags: Amazon Premium Union-find DFS Graph
// Time:  O((m + n)ackr(n)) ~ O(m), m = number of operations/edges
// Space: O(n)
// Same as 0547-friend-circles
// Read 1627-graph-connectivity-with-threshold for time complexity
class UnionFind {
    vector<int> parent;
    vector<int> size;
public:
    int count;
    UnionFind(int n): parent(n), size(n, 1) {
        for (auto i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        count = n;
    }
    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    
    bool Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false;
        if (size[pu] > size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        --count;
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &edge: edges)
            uf.Union(edge[0], edge[1]);
        return uf.count;
    }
};
