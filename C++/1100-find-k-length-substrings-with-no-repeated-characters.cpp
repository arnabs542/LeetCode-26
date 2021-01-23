// Tags: String Sliding-window Amazon Premium
// Time: O(n)
// Space: O(n)
// Similar to 0003-longest-substring-without-repeating-characters
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        // stores last know index of each char
        unordered_map<int, int> mp;
        int res = 0;
        for (int left = 0, right = 0; right < S.length(); ++right) {
            if (mp.count(S[right]))
                left = max(left, mp[S[right]] + 1);
            mp[S[right]] = right;
            if (right - left + 1 == K) {
                ++res;
                ++left;
            }
        }
        return res;
    }
};
