// Tags: Amazon Stack Two-pointers
// Time: O(n * n/k), atmost n/k recursive calls
// Space: O(n * n/k)
// Brute force, recursive
class Solution {
public:
    string removeDuplicates(string s, int k) {
        for (auto i = 1, cnt = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1])
                cnt = 1;
            else if (++cnt == k)
                return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
        }
        return s;
    }
};



// Time: O(n * n/k), atmost n/k recursive calls
// Space: O(1)
// Brute force, iterative
class Solution {
public:
    string removeDuplicates(string s, int k, bool replaced = true) {
        while (replaced) {
            replaced = false;
            for (auto i = 1, cnt = 1; i < s.length(); ++i) {
                if (s[i] != s[i - 1])
                    cnt = 1;
                else if (++cnt == k) {
                    s = s.substr(0, i - k + 1) + s.substr(i + 1);
                    replaced = true;
                    // cnt = 1;
                }
            }
        }
        return s;
    }
};



// Time: O(n)
// Space: O(n)
// Two pointers
class Solution {
public:
    string removeDuplicates(string s, int k, bool replaced = true) {
        // track the running count for each character
        vector<int> cnt(s.length(), 1);

        // next index in the resultant string
        // available to be written
        auto j = 0;
        for (auto i = 0; i < s.length(); ++i, ++j) {
            // shift characters after removing duplicates
            s[j] = s[i];
            if (j > 0 && s[j] == s[j - 1])
                cnt[j] = cnt[j - 1] + 1;
            else
                cnt[j] = 1; // overwrite previous count
            if (cnt[j] == k)
                j -= k;
        }
        return s.substr(0, j);
    }
};



// Time: O(n)
// Space: O(n)
// Stack
class Solution {
public:
    string removeDuplicates(string s, int k, bool replaced = true) {
        // stack to store (char, its count) pairs
        vector<pair<char, int>> st;
        string res;
        for (auto c: s) {
            if (st.empty() || st.back().first != c)
                st.push_back({c, 1});
            else if (++st.back().second == k)
                st.pop_back();
        }

        // create resultant string
        for (auto &p: st) {
            res += string(p.second, p.first);
        }
        return res;
    }
};
