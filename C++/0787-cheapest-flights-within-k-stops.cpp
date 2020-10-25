// Time:  O((|E| + |V|* log|V|)
// Space: O(|E| + |V|) = O(|E|)

//typedef tuple<int,int,int> T
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &f: flights)
            adj[f[0]].emplace_back(f[1],f[2]);
            // or .push_back({f[1], f[2]})
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        // K intermediate vertices ----> K+1 edges
        min_heap.emplace(0, src, K+1);
        // stops mean edges remaining not vertices
        while (!min_heap.empty()) {
            auto [cost, u, stops] = min_heap.top(); min_heap.pop();
            // or tie(cost, u, stops)
            if (u == dst) return cost;
            // skip if not stops remaining
            if (!stops) continue;
            for (auto to: adj[u]) {
                auto [v, w] = to;
                // or tie(v, w)
                min_heap.emplace(cost+w, v, stops-1);
            }
        }
        return -1;
    }
};


// Notes:
// A vertex once popped from heap can come again with more stops used but it
// won't be an issue since whichever has min cost will be picked first.
// We are keeping all copies of same vertex because if a particular copy can't be
// used because of k limitation, we can choose another one.
// Also, its like bellmann ford whether we keep considering same vertex again if
// there is another edge leading to it.
// Difference from Djistras: Instead of decrease key, we push new copy.
