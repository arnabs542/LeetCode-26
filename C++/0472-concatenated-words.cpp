// Tags: DP Amazon Trie
// Time: O(n * l^2), n = length of word list, l = average length of a word
// Space: O(n)
// Using Word Break 0139
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (const auto &w: words) {
            if (wordBreak(w, dict))
                res.push_back(w);
        }
        return res;
    }
    
    bool wordBreak(string word, unordered_set<string> &dict) {
        if (word.empty())
            return false;
        int n = word.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        dict.erase(word);
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j)
                if (dp[j] && dict.count(word.substr(j + 1 - 1, i - j))) {
                    dp[i] = true;
                    break;
                }
        }
        dict.insert(word);
        return dp[n];
    }
};
