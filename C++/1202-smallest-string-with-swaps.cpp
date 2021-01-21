// Tags: Union-find
// Time: O(n log n), in worst case all indices may be part of one set/cycle
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf((int)s.size());
        for (const auto &p: pairs)
            uf.Union(p[0], p[1]);
        
        // key: root (index) of each union group, value: (indices to) all its characters
        vector<vector<int>> m(s.size());
        // since we are iterating from left to right, indices will always be sorted
        for (int i = 0; i < s.length(); ++i)
            m[uf.Find(i)].push_back(i);

        for (const auto &ids: m) {
            string ss;
            for (auto id: ids)
                ss += s[id];
            sort(ss.begin(), ss.end());
            // no need to sort ids (already sorted)
            for (auto i = 0; i < ids.size(); ++i)
                s[ids[i]] = ss[i];
        }
        return s;
    }
};
/*
Intuition:
If a group of characters is interconnected by swap pairs,
you can freely rearrange characters within that group.

Solution:
* Identify groups using union-find. For each group, collect 
  all its characters in a string.
* Sort the string, then put the rearranged characters back to
  their respective positions in the group.
*/
