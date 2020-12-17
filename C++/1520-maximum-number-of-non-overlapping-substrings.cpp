// Tags: Amazon Greedy
// Time: O(26*n), the inner loop could go through n elements, 
// but the outer loop will do it no more than 26 times.
// Space: O(n)
class Solution {
    int checkSubstr(int i, string s, vector<int> &l, vector<int> &r) {
        int right = r[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            // not a valid substring
            if (l[s[j] - 'a'] < i)
                return -1;
            right = max(right, r[s[j] - 'a']);
        }
        return right;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        for (auto i = 0; i < s.length(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }
        // right for previous substring
        int right = -1;
        vector<string> res;
        for (auto i = 0; i < s.length(); ++i) {
            // start of potential valid substring (at most 26 times)
            if (l[s[i] - 'a'] == i) {
                int new_right = checkSubstr(i, s, l, r);
                if (new_right != -1) {
                    // start new string
                    if (i > right)
                        res.push_back("");
                    // replace with smaller right edge
                    right = new_right;
                    // replace with smaller substring
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        return res;
    }
};

/*
The greedy logic is quite simple:
    There could be no more that 26 valid substrings; each potential valid substring starts from the first occurrence of a given character.
    If we find a valid substring, and then another valid substring within the first substring - we can ignore the larger substring.
        E.g. if we find "abccba", and then "bccb", and then "cc", we only care about "cc". This can be easily proven by a contradiction.

Algorithm:
    First, collect left (l) and right(r) indices for every character.
    Then, go through the string. If the current index i is the left index for the character s[i], it may be a valid substring.
        We then use a sliding window pattern to find the length of the substring.
            If we find a character that appears before i - we do not have a valid string starting at i.
        If substring is valid, we remember it, as well as it's right edge.
        This logic, repeated, will ensure that we find the valid substring with the smallest right edge.
    If the valid substring starts after the previous right edge, there is no overlap. The previous substring should be included into the result.
*/
