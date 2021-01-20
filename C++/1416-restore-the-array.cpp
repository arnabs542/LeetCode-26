// Tags: DP Amazon
// Time: O(s*logk), logk denotes the number of digits in number k
// (at each starting index, we iterate string upto logk length)
// (easier to understand if we look at Bottom-up solution)
// Space: O(s)
// Top-down Dp, Dfs + Memoization
class Solution {
    int dp[100001] {};
    int dfs(string &s, int i, int k) {
        if (i == s.size())
            return 1;
        // since there are no leading zeros
        // we can't have any number starting with 0
        if (s[i] == '0')
            return 0;
        
        if (!dp[i]) {
            // len denotes length of substring s[i : j]
            // j pointer is at i + len - 1
            long num = 0;
            for (int len = 1; i + len <= s.size(); ++len) {
                num = 10*num + s[i + len - 1] - '0';
                if (num > k)
                    break;
                dp[i] = (dp[i] + dfs(s, i + len, k)) % 1000000007;
            }
        }
        return dp[i];
    }
public:
    int numberOfArrays(string s, int k) {
        return dfs(s, 0, k);
    }

/*
dp[i] denotes number of possible arrays that can be printed
        for string s[i:]

dp[i] = sigma dp[i + len] for len = 1 ..... (s.length() - i)
        if s[i: i + len - 1] < k

Base case:
dp[s.length()] = 1 (only one way for an empty string)
*/



// Time: O(s*logk)
// Space: O(s), don't need memory for stack compared to above
// solution
// Bottom-up Dp
class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length() + 1);
        dp[s.size()] = 1;
        // iterate right to left
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            long num = 0;
            for (int len = 1; i + len <= s.size(); ++len) {
                num = num*10 + s[i + len - 1] - '0';
                if (num > k)
                    break;
                dp[i] = (dp[i] + dp[i + len]) % 1000000007;
            }
            
        }
        return dp[0];
    }
};

// To do: memory optimized O(logk) space solution
