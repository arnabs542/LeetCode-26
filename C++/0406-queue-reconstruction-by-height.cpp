// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             {return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];});

        vector<vector<int>> result;
        for (const auto &p: people) {
            // insert at index k
            result.insert(result.begin() + p[1], p);
            // or result.emplace()
        }
        return result;
    }
};
