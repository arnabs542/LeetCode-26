// Tags: Amazon DP Backtracking
// Time: O(s.size() * (avg list size))
// Space: O(s.size() * (avg list size * avg string size)
// Memoization solution
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        // could also use vector<vector<string>> dp(s.size()); instead
        // dp[s.size()] = {""};
        unordered_map<int, vector<string>> dp {{s.size(), {""}}};

        // returns a list of all sentences that can be built from 
        // suffix s[i:]
        // return type: vector<string>
        // argument types: int
        function<vector<string>(int)> sentences = [&] (int i) {
            if (!dp.count(i)) {
                for (int j = i + 1; j <= s.size(); ++j) {
                    if (dict.count(s.substr(i, j - i))) {
                        // j points to the very next index after a
                        // word is found
                        for (string tail: sentences(j)) {
                            dp[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
                        }
                    }
                }
            }
            return dp[i];
        };

        return sentences(0);
    }
};
