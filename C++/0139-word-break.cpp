// Tags: DP Amazon
// Time:  O(n * l), l is the max length of the words, (if unordered_set is used)
// Space: O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.length();
        size_t max_len = 0;
        // unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        for (const auto &str: wordDict)
            max_len = max(max_len, str.length());

        vector<bool> canBreak(n+1, false);
        canBreak[0] = true;

        for (int i = 1; i <= n; ++i)
            for (int l = 1; l <= max_len && i - l >= 0; ++l) {
                // if (canBreak[i - l] && word_set.count(s.substr(i - l + 1 - 1, l)))
                // if unordered_set is used
                if (canBreak[i - l] && contain(wordDict, s.substr(i - l, l))) {
                    canBreak[i] = true;
                    break;
                }
            }
        return canBreak[n];
    }

    bool contain(vector<string>& wordDict, string s){
        for(const auto &word: wordDict){
            if(s == word) return true;
        }
        return false;
    }
};
