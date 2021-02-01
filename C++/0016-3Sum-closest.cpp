// Tags: Array Two-pointers
// Time: O(n^2)
// Space: O(1)
// Similar to 0015-3Sum
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, min_diff = INT_MAX;
        for (int i = nums.size() - 1; i >= 2; --i) {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
                continue;
            int left = 0, right = i - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total < target)
                    ++left;
                else if (total > target)
                    --right;
                else
                    return target; // when min_diff = 0
                if (abs(total - target) < min_diff) {
                    min_diff = abs(total - target);
                    res = total;
                }
            }
        }
        return res;
    }
};
