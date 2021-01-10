// Tags: String Stack Amazon
// Time:  O(n)
// Space: O(n)
// Similar to 0224-basic-calculator
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string cur;
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                num = 10*num + (s[i] - '0');
            } else if (s[i] == '[') {
                st.push(cur);
                st.push(to_string(num));
                cur = "";
                num = 0;
            } else if (s[i] == ']') {
                int times = stoi(st.top()); st.pop();
                string prev = st.top(); st.pop();
                while (times-- > 0) {
                    prev += cur;
                }
                cur = prev;
            } else {
                cur += s[i];
            }
        }
        return cur;
    }
};
