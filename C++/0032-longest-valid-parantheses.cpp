// Tags: Stack DP Top-100-liked
// Time: O(n)
// Space: O(n)
// Dp solution
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1)
            return 0;
        vector<int> dp(s.length(), 0);
        int res = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i - 2 >= 0) ? dp[i - 2] + 2: 2;
                if (s[i - 1] == ')') {
                    // ( just before the one s[i - 1] is closing
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                        dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
/*
dp[i] = length of the longest valid substring ending at ith index

It is obvious that the valid substrings must end with ')'

=> substrings ending with '(' will always contains 0 in their corresponding
dp indices.
")()())"

1. If s[i] = ')' and s[i - 1] = '(' ie string looks like "......()"

    dp[i] = dp[i - 2] + 2   (it is closing the bracket just before it)
    
2. If s[i] = ')' and s[i - 1] = ')' ie string looks like "......))"
   & if s[i - dp[i - 1] - 1] = '('  ie string actually looks like "...((....))"

    dp[i] = dp[i - dp[i - 1] - 2] + d[i - 1] + 2 
    
    (it is closing the bracket at i - dp[i - 1] - 1)
*/



// Time: O(n)
// Space: O(n)
// Using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // first start index
        st.push(-1);
        int res = 0;
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                // s[i] == ')'
                st.pop(); // (stack atleast has -1)
                if (st.empty()) {
                    // new start index;
                    st.push(i);
                } else {
                    // calculate length of current substring
                    // from the available start index.
                    // & update the longest substring.
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};



// Reusing 1249-minimum-remove-to-make-valid-parantheses
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*'; st.pop();
        }
        int res = 0, left = 0;
        for (auto i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == '*') {
                res = max(res, i - left);
                left = i + 1;
            }
        }
        return res;
    }
};
