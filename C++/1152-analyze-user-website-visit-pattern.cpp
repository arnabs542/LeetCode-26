// Tags: Amazon Hash-table Sort Array
// Time:  O(n^3)
// Space: O(n), not sure
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username,
      vector<int>& timestamp, vector<string>& website)
    {
        // unordered map of map ordered by keys(timestamp)
        unordered_map<string, map<int, string>> m;
        // count of each 3-sequence
        unordered_map<string, int> cnt;

        for (int i = 0; i < username.size(); ++i)
            m[username[i]][timestamp[i]] = website[i];

        // u.second denotes map<int, string> as elements are stored as key, value
        // std::pair
        for (auto u: m) {
            unordered_set<string> ts;
            // shoulde be prev(u.second.end(), 2), prev(u.second.end()), u.second.end()
            // why it works with u.second.end() in every case?
            for (auto it = begin(u.second); it != end(u.second); ++it)
                for (auto it1 = next(it); it1 != end(u.second); ++it1)
                    for (auto it2 = next(it1); it2 != end(u.second); ++it2)
                        ts.insert(it->second + "$" + it1->second + "#" + it2->second);
            for (auto s: ts)    ++cnt[s];
        }
        string res;
        int max_cnt = 0;
        for (auto t: cnt) {
            if (t.second >= max_cnt) {
                res = res == "" || max_cnt < t.second ? t.first : min(res, t.first);
                max_cnt = t.second;
            }
        }
        auto p1 = res.find("$"), p2 = res.find("#");
        return {res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1), res.substr(p2 + 1)};
    }
};
