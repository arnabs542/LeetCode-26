// Tags: WC235 Math
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long res = 0, to_sub = 0;
        // set makes binary search faster as there may be multiple
        // instances of same number
        set<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < nums1.size(); ++i) {
            long orig = abs(nums1[i] - nums2[i]);
            res += orig;
            // optimization: no need to replace if orig <= to_sub
            // as even if orig becomes 0, previous to_sub will still
            // be better
            if (orig > to_sub) {
                auto it = s.lower_bound(nums2[i]);
                // > nums2[i]
                if (it != s.end())
                    to_sub = max(to_sub, orig - abs(*it - nums2[i]));
                // = nums2[i]
                if (it != s.begin())
                    to_sub = max(to_sub, orig - abs(*prev(it) - nums2[i]));
            }
        }
        return  (res - to_sub) % 1000000007;
    }
};
