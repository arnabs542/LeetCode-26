// Tags: Union-find Graph Amazon Premium
// Time: O((E + N)logN)
// Space: O(E + N)
// Prim's algorithm
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        // cost, node
        using T = pair<int, int>;
        vector<vector<T>> adj(N + 1);
        vector<bool> visited(N + 1);
        vector<int> min_cost(N + 1, INT_MAX);
        for (auto& edge : connections) {
            adj[edge[0]].push_back({edge[2], edge[1]});
            adj[edge[1]].push_back({edge[2], edge[0]});
        }
        priority_queue<T, vector<T>, greater<T>> min_heap;
        // cost to our tree (unlike Dijkstra's, not cost to source)
        min_heap.push({0, 1});
        int res = 0, num_visited = 0;
        while (num_visited < N && !min_heap.empty()) {
            // delete min O(NlogN)
            auto [cost, city] = min_heap.top();
            min_heap.pop();
            if (visited[city])
                continue;

            visited[city] = true;
            ++num_visited;
            res += cost;
            
            // decrease key O(ElogN)
            for (auto v : adj[city]) {
                int ncost = v.first;
                int ncity = v.second;
                if (!visited[ncity] && ncost < min_cost[ncity]) {
                    min_cost[ncity] = ncost;
                    min_heap.push({ncost, ncity});
                }
            }
            
        }
        return num_visited == N ? res : -1;
    }
};



// Time: O(ElogE + N)
// Space: O(N)
// Kruskal's algorithm
class UnionFind {
    vector<int> parent;
    vector<int> size;
public:
    UnionFind (int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
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
        return true;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        auto cmp = [&] (const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        };
        sort(connections.begin(), connections.end(), cmp);
        UnionFind uf(N + 1);
        int res = 0, cnt = 0;
        for (auto& c : connections) {
            if (uf.Union(c[0], c[1])) {
                // union successful, the edge doesn't create cycle
                res += c[2];
                ++cnt;
            }
            if (cnt == N - 1)
                return res;
        }
        return -1;
    }
};
