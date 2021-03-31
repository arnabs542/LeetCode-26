// Tags: Amazon String Stack
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> symbol_pair {{')','('}, {'}','{'}, {']','['}};
        // closing brackets
        stack<char> st;
        for (const auto &c : s) {
            const auto &it = symbol_pair.find(c);
            // constant iterator
            if (it == symbol_pair.cend()) {
                // not a closing bracket
                st.emplace(c);
                // push
            } else {
                // is a closing bracket
                // or st.top() != symbol_pair[c]
                if (st.empty() || st.top() != it->second) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
