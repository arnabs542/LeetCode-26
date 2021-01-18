// Tags: Premium
// Time: O(n)
// Space: O(1)
// Same as 0340-longest-substring-with-at-most-k-distinct-characters
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int k = 2;
        int res = 0, distinct = 0;
        array<int, 256> cnt {0};
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (cnt[s[right]]++ == 0)
                ++distinct;
            while (distinct > k) {
                if(--cnt[s[left]] == 0)
                    --distinct;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
