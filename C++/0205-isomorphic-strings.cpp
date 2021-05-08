// Tags: Hash-table Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        // record the last position of each ascii char
        vector<int> sm(256, -1), tm(256, -1);
        for (auto i = 0; i < s.length(); ++i) {
            // contradict mapping.
            if (sm[s[i]] != tm[t[i]])
                return false;
            sm[s[i]] = i;
            tm[t[i]] = i;
        }
        return true;
    }
};
/*
Traverse the character of both s and t on the same position, 
if their mapping values in sm and st are different, means they
are not mapping correctly, return false
*/



// First attempt, failed for 
// s = "bbbaaaba", t = "aaabbbba"
// Idea of 1653-determine-if-two-strings-are-close
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> scnt(26), tcnt(26);
        for (auto c : s)
            ++scnt[c - 'a'];
        for (auto c : t)
            ++tcnt[c - 'a'];
        sort(scnt.begin(), scnt.end());
        sort(tcnt.begin(), tcnt.end());
        return scnt == tcnt;
    }
};
