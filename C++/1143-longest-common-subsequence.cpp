// Time:  O(m * n)
// Space: O(min(m, n))
// DP solution
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.length() > text1.length())
            return longestCommonSubsequence(text2, text1);

        vector<vector<int>> opt(2, vector<int>(text2.length() + 1));

        for (int i = 1; i <= text1.length(); ++i)
            for (int j = 1; j <= text2.length(); ++j)
                opt[i % 2][j] = (text1[i - 1] == text2[j - 1]) ? opt[(i - 1) % 2][j - 1] + 1 : max(opt[(i - 1) % 2][j], opt[i % 2][j-1]);

        return opt[text1.length() % 2][text2.length()];
    }
};

/*
Notes:
We assume text2 is always smaller in length.
i means the ith element of X and ith element of X is at index i-1

opt[i][j] = (s[i - 1] == s[j - 1]) ? opt[i-1, j-1] : max(opt[i - 1, j], opt[i, j - 1]);
Base case:
opt[i][0] = opt[0][j] = 0;
*/
