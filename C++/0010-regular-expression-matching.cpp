// Tags: DP String
// Time: O(m*n)
// Space: O(m*n)
// Dp solution
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, false));
        dp[0][0] = true;
        // s = "" and p = "a*" or "a*b*" or "a*b*c*".. so on
        for (auto j = 2; j < dp[0].size(); ++j) {
            // p is 0th base indexed
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        for (auto i = 1; i < dp.size(); ++i) {
            for (auto j = 1; j < dp[0].size(); ++j) {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 1 - 1] == '.' || s[i - 1] == p[j - 1 - 1]) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

/*
dp[i][j] = true if regular expression matches from 0.....i in s (text)
to 0......j in p (pattern)

Recurrence:
    dp[i][j] = true if s1.....si matches p1......pj
If (s[i] == s[j]) || p[j] == '.')
    dp[i][j] = dp[i - 1][j - 1]

else if (p[j] == '*')
    0 occurence of p[j - 1]:
        dp[i][j] = dp[i][j - 2]
    
    1 or more occurence of p[j - 1], (s[i] == p[j - 1] || p[j - 1] == '.'):
                   || dp[i - 1][j]
else
    dp[i][j] = false

Base Cases:
    dp[0][0] = true (empty text and empty pattern)
    dp[i][0] = false (empty pattern)
    dp[0][j] = false/true (empty text, example: s = "", p = "a*b*")
*/




// Time: O(m + n)
// Space: O(min(m,n)), not sure
// Recursion
class Solution {
    bool helper(string s, string p, int i, int j) {
        // if j has reached end of pattern means j should also reach end of text for match
        // to happen
        if (j == p.length())
            return i == s.length();

        // if next character is not * means either current value at pattern and text should be same
        // or current value at pattern should be . in which case you can skip one character of text
        if (j == p.length() - 1 || p[j + 1] != '*')
            return i < s.length() && (p[j] == '.' || s[i] == p[j]) && helper(s, p, i + 1, j + 1);

        // if we have case like abc and ad*bc so here we totally skip d*
        if (helper(s, p, i, j + 2))
            return true;

        // For case like abbc and ab*c match first b with b* and then next b to c. If that does not work out
        // then try next b with b* and then c with c and so on.
        // if pattern current val is . then skip one character at time from text till we either reach end of text
        // or a match is found
        while (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            if (helper(s, p, i + 1, j + 2))
                return true;
            ++i;
        }

        return false;
    }

public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
};
