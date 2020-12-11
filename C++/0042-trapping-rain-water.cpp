// Tags: Amazon Two-pointers Array
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int i = 0, j = height.size() - 1;
        int left_max = height[0], right_max = height[height.size() - 1];
        int res = 0;
        while (i < j) {
            // ensures we always put water upto
            // the minimum height
            if (left_max < right_max) {
                ++i;
                // fill in the gap
                res += max(0, left_max - height[i]);
                // update current max height from left
                left_max = max(left_max, height[i]);
            } else {
                --j;
                // fill in the gap
                res += max(0, right_max - height[j]);
                // update current max height from right
                right_max = max(right_max, height[j]);
            }
        }
        return res;
    }
};
