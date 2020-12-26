// Tags: Backtracking DFS Top-interview
// Time: O(2^n), each char has two choices either to continue with previous
// substring or start a new substring
// Space: O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s, res, cur, 0);
        return res;
    }
    
    void helper(string s, vector<vector<string>> &res, vector<string> &cur, int i) {
        if (i == s.length()) {
            res.push_back(cur);
            return;
        }
        
        for (int j = i; j < s.length(); ++j) {
            if (isPalindrome(s, i, j)) {
                cur.push_back(s.substr(i, j - i + 1));
                helper(s, res, cur, j + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
