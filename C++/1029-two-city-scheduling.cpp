// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [] (auto &v1, auto &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        };
        // whether the element passed as first arg is considered to go before
        // the second ie. smallest difference first

        sort(costs.begin(), costs.end(), cmp);
        int res = 0;
        for (auto i = 0; i < costs.size()/2; ++i)
            res += costs[i][0] + costs[costs.size()/2 + i][1];

        return res;
    }
};

// Notes:
// We sort the array by the difference between costs for A and B.
// Then, we fly first N people to A, and the rest - to B.
// let's say two person, p0 and p1, if p0[0] - p0[1] < p1[0] - p1[1], 
// it equals to p0[0] + p1[1] < p1[0] + p0[1], which means p0 to A and
// p1 to B is cheaper than vice verse.
