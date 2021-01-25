// Tags: Stack Amazon
// Time:  O(n)
// Space: O(n)
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> res(n);
        int cur_start = 0; // start of current time duration
        for (const auto& log : logs) {
            vector<string> tokens = split(log, ':');
            if (tokens[1] == "start") {
                if (!st.empty()) {
                    res[st.top()] += stoi(tokens[2]) - cur_start;
                }
                st.push(stoi(tokens[0]));
                cur_start = stoi(tokens[2]);
            } else {
                res[st.top()] += stoi(tokens[2]) - cur_start + 1;
                st.pop();
                cur_start = stoi(tokens[2]) + 1;
            }
        }
        return res;
    }
private:
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }
};
