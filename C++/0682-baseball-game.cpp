// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for (size_t i = 0; i < ops.size(); ++i) {
            int n = st.size();
            if (ops[i] == "+")
                st.push_back(st[n - 1] + st[n - 2]);
            else if (ops[i] == "C")
                st.pop_back();
            else if (ops[i] == "D")
                st.push_back(st[n - 1]*2);
            else
                st.push_back(stoi(ops[i]));
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};
