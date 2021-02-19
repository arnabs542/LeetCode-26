// Tags: Greedy Stack String Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // count apprearance of each char
        vector<int> cnt(26);
        // mark that we have used the char before
        vector<bool> used(26);
        for (char c: s)
            ++cnt[c - 'a'];
        string res;
        for (char c: s) {
            --cnt[c - 'a'];
            // 1. already used c
            if (used[c - 'a'])
                continue;
            // haven't used char c before
            // 2. if c < res.back() and there are remaining res.back() chars after c
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
                // mark them unused
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            // append to result
            res += c;
            used[c -'a'] = true;
        }
        return res;
    }
};



// First attempt, wrong solution
// Input: "cbacdcbc"
// Output: "bacd"
// Expected: "acdb"
// This approach doesn't work as in this question we are talking about a resultant subsequence
// not a substring. => read question carefully
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> pos(26, -1);
        int max_len = 0;
        string res;
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (pos[s[right] - 'a'] != -1) {
                left = max(left, pos[s[right] - 'a'] + 1);
            }
            if (right - left + 1 >= max_len) {
                res = right - left + 1 > max_len ? s.substr(left, right - left + 1) :
                    s.substr(left, right - left + 1) < res ?
                        s.substr(left, right - left + 1) : res;
                max_len = right - left + 1;
            }
            pos[s[right] - 'a'] = right;
        }
        return res;
    }
};
