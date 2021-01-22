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
            // 2. if c < res.back() and they are remaining res.back() chars after c
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
