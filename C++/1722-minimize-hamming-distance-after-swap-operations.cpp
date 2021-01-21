// Tags: Union-find WC223 Greedy
// Time:  O(n * α(n)) ~= O(n)
// Space: O(n)
class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n): parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int Find(int u) {
        if (parent[u] == u)
            return u;
        // path compression
        return parent[u] = Find(parent[u]);
    }
    
    void Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
        if (pu != pv) {
            // union by rank
            if (size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }  
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        // indices are from 0 to n-1
        UnionFind uf(n);
        for (const auto &as: allowedSwaps) {
            uf.Union(as[0], as[1]);
        }
        // find elements of each union-find group
        // key: root of each union group, value: map (number to its count)
        unordered_map<int, unordered_map<int, int>> mp;
        
        // iterate over source
        for (int i = 0; i < n; ++i) {
            // root of union group/set
            int p = uf.Find(i);
            // in this group number source[i] is present and with this count
            ++mp[p][source[i]];
        }
        
        int diff = 0;
        // iterative over target
        // greedy fit the target, if not, diff++
        for (int i = 0; i < n; ++i) {
            int num = target[i];
            int p = uf.Find(i);
            if (mp[p][num] <= 0)
                ++diff;
            else
                --mp[p][num]; // this number has already been used
        }
        return diff;
    }
};
