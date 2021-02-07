// Tags: Amazon String DP Expand-from-middle
/* Bruce Force approach: Create all substring - O(n^2),
nC2 (excluding the trivial solution where a character itself is a palindrome).
Now iterate once and check if the substring is palindrome.
Then return the largest palidromic substring- O(n^3)
*/

/* Expand Around Center approach:
Two cases:
a.  "racecar"
b.  "aabbaa"

Time: O(n^2)
Space: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1)
            return "";

        int start = 0;
        int end = 0;

        for (int i=0; i<s.length(); i++){
            // racecar
            int len1 = expandFromMiddle(s,i,i);
            // aabbaa
            int len2 = expandFromMiddle(s,i,i+1);
            int len = max(len1,len2);
            if (len > end - start + 1){
                start = i - (len-1)/2;
                end = i + len/2 ;
            }

        }
        return s.substr(start,end-start+1);

    }
private:
    int expandFromMiddle(string s, int left, int right){
        if (left > right){
            return 0;
        }

        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
        // -1 because left and right both moves one pos extra.
    }
};



// Time: O(n^2)
// Space: O(n^2)
// Dp solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), max_len = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        string res;
        for (int j = 0; j < n; ++j) {
            // try all length substrings (1, 2, ....) ending at j
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        res = s.substr(i, max_len);
                    }
                }
            }
        }
        return res;
    }
};

/*
opt[i, j] = true if the substring si,.......,sj is a palindrome

opt[i, j] = opt[i + 1, j - 1] && s[i] == s[j]

base case:
opt[i, i] = true
opt[i, i+1] = (si == sj)

j-i < 2 covers both base cases ie. when j-i == 0 and when j-i == 1
*/
