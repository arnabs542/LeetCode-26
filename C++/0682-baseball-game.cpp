// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for (size_t i = 0; i < ops.size(); ++i) {
            int n = res.size();
            if (ops[i] == "+")
                res.push_back(res[n - 1] + res[n - 2]);
            else if (ops[i] == "C")
                res.pop_back();
            else if (ops[i] == "D")
                res.push_back(res[n - 1]*2);
            else
                res.push_back(stoi(ops[i]));
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
