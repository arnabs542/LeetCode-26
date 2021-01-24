// Tags: Stack String Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string res, cur;
        vector<string> st;
        while (getline(ss, cur, '/')) {
            if (cur == "." || cur.empty())
                continue;
            if (cur == "..") {
                // come out of last subdirectory
                if(!st.empty())
                    st.pop_back();
            } else
                st.push_back(cur);
        }
        for (string& s : st)
            res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
