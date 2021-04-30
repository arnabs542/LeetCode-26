// Tags: DP Two-pointers Google
// Time: O(m*n)
// Space: O(1)
// Two pointers solution
class Solution {
public:
    string minWindow(string S, string T) {
        string res;
        int min_width = S.length() + 1;
        for (int i = 0, j = 0; i < S.length(); ++i) {
            // go from left to right
            if (S[i] == T[j]) {
                ++j;
                if (j == T.length()) {
                    // T has been fully traversed in forward direction
                    int end = i + 1;
                    --j;
                    // go from right to left
                    while (j >= 0) {
                        if (S[i] == T[j])
                            --j;
                        --i;
                    }
                    // T has been fully traversed in backward direction
                    ++j;
                    // increment i so that the same substring W is not considered again
                    // (i will be incremented again at the end of loop)
                    ++i;
                    // record result
                    if (end - i < min_width) {
                        min_width = end - i;
                        res = S.substr(i, min_width);
                    }
                }
            }
        }
        return res;
    }
};
/*
1. Take two pointer and start moving i left to right (incrementing j, everytime there ia a
   match).

2. Once j is fully explored, we save the position of i as 'end'. Then we put back
   i and j a step back and start moving i in backward direction (decrementing j, everytime
   there is a match.)

3. At this point, the possible shortest substring W is S[i : end].

4. Bring back i and j a step in forward direction and continue searching for a better
   substring W.
*/



// Time: O(m * n)
// Space: O(m * n)
// Dp solution
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.length(), n = T.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i + 1;
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (S[i - 1] == T[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int start = 0, min_len = m + 1;
        for (int i = 1; i <= m; ++i) {
            if (dp[i][n] != -1) {
                if (i - dp[i][n] + 1 < min_len) {
                    min_len = i - dp[i][n] + 1;
                    start = dp[i][n] - 1;
                }
            }
        }
        return min_len == m + 1 ? "" : S.substr(start, min_len);
    }
};
/*
dp[i][j] = largest starting index for substring W in S for which T[1:j] is a subsequence
           of S[1:i]
           otherwise
           -1 if such valid substring doesn't exit

dp[i][j] = dp[i - 1][j - 1] if S[i] == T[j]
           else
           dp[i - 1][j]

Base case:
dp[i][0] = i + 1

Finally, go through the last column to find the substring with min length.
*/
