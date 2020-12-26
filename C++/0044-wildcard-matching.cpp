// Tags: DP String Top-interview
// Similar to 0010-regular-expression-matching
// Time: O(m*n)
// Space: O(m*n)
// Dp solution
class Solution {
public:
    bool isMatch(string s, string p) {
        // replace multiple * with one *
        // e.g a**b***c --> a*b*c
        int writeIndex = 0;
        bool isFirst = true;
        for (auto i = 0; i < p.length(); ++i) {
            if (p[i] == '*') {
                if (isFirst) {
                    p[writeIndex++] = p[i];
                    isFirst = false;
                }
            } else {
                p[writeIndex++] = p[i];
                isFirst = true;
            }
        }

        vector<vector<bool>> dp(s.length() + 1, vector<bool>(writeIndex + 1));

        if (writeIndex > 0 && p[0] == '*')
            dp[0][1] = true;
        dp[0][0] = true;
        
        for (auto i = 1; i < dp.size(); ++i) {
            for (auto j = 1; j < dp[0].size(); ++j) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        
            }
        }
        return dp[s.length()][writeIndex];
    }
};

/*
dp[i][j] = true if expression matches from 0.....i in s (text)
to 0......j in p (pattern)

Recurrence:
    dp[i][j] = true if s1.....si matches p1......pj
If (s[i] == s[j]) || p[j] == '?')
    dp[i][j] = dp[i - 1][j - 1]

else if (p[j] == '*')
    skip *:
        dp[i][j] = dp[i][j - 1]
    
    multiple seq of characters:
                   || dp[i - 1][j]
else
    dp[i][j] = false

Base Cases:
    dp[0][0] = true (empty text and empty pattern)
    dp[0][1] = true if p[0] == '*'
*/



// Time: O(m + n)
// Space: O(min(m,n)), not sure
// Recursion
// Time limit exceeded
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

    bool helper(string s, string p, int i, int j) {
        if (j == p.length())
            return i == s.length();
        
        if (p[j] != '*')
            return i < s.length() && (p[j] == '?' || s[i] == p[j]) && helper(s, p, i + 1, j + 1);
        
        // if we have a***b then skip to the last *
        while (j < p.length() - 1 && p[j + 1] =='*')
            ++j;

        --i;// so that we can test helper(i, j + 1) as well
        while (i < (int) s.length()) {
            if (helper(s, p, i + 1, j + 1))
                return true;
            ++i;
        }
        return false;
    }
};
