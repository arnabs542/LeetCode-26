// Tags: Sliding-window String Hash-table Amazon Premium
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, distinct = 0;
        array<int, 256> cnt {0};
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (cnt[s[right]]++ == 0)
                ++distinct;
            // condition when order is disturbed
            while (distinct > k) {
                // steps taken to correct the disturbance
                if(--cnt[s[left]] == 0)
                    --distinct;
                ++left;
            }
            // update the result
            res = max(res, right - left + 1);
        }
        return res;
    }
};
/*
Substrings which have less than k distinct characters are also valid
for "eceba" & k = 2
valid substrings are {"", e, c, e, b, a, ec, ce, eb, ba, ece}
=> longest valid substring is ece
*/
