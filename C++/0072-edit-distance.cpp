// Tags: DP String Top-100-liked Amazon
// Time: O(n*m)
// Space: O(n*m)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]; // match
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    // replace, delete, insert
            }
        }
        return dp[m][n];
    }
};

/*
dp[i][j] = edit distance between x1.....xi and y1......yj

dp[i][j] = dp[i - 1][j - 1] if s[i] == s[j]

        else:
            min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1
            
            min(Replace, Delete, Insert)
Base case:
    dp[i][0] = i (all delete)
    dp[0][j] = j (all insert)
*/



// Time: O(n*m)
// Space: O(n)
// Using two vectors
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // pre denotes i - 1 and cur denotes i
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int j = 1; j <= n; j++)
            pre[j] = j;
        
        for (int i = 1; i <= m; i++) {
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre[j - 1];
                } else {
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
            // pre.swap(cur);
            // or pre = cur;
            // fill(cur.begin(), cur.end(), 0);
        }
        return pre[n];
    }
};
