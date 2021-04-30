// Tags: Amazon BFS Path.ai
// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        // bus stop to indices of bus routes which go through it
        unordered_map<int, vector<int>> stop2routes;
        for (auto i = 0; i < routes.size(); ++i)
            for (const auto &stop : routes[i])
                stop2routes[stop].push_back(i);
        // visited bus routes
        unordered_set<int> visited;
        // current level stops
        vector<int> curLev{S};
        int buses = 0;
        while (!curLev.empty()) {
            // next level stops
            vector<int> nextLev;
            ++buses;
            for (auto &stop :  curLev) {
                for (auto &i : stop2routes[stop]) {
                    // this route bus already taken
                    if (visited.count(i))
                        continue;
                    visited.insert(i);
                    for (auto &nextStop : routes[i]) {
                        // prevent current stop from being pushed onto next level
                        if (nextStop == stop)
                            continue;
                        // destination reached
                        if (nextStop == T)
                            return buses;
                        nextLev.push_back(nextStop);
                    }
                }
            }
            curLev = nextLev;
        }
        return -1;
    }
};
