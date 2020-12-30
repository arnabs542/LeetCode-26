// Tags: String Stack Tiktok
// Time: O(n)
// Space: O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // stores indices
        stack<int> st;
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*'; st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
