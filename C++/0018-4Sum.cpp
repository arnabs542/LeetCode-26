// Tags: Array Two-pointers Amazon
// Time: O(n^3)
// Space: O(1)
// Same idea as 0015-3Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < static_cast<int>(nums.size()) - 3; ++i) {
            for (int j = i + 1; j < static_cast<int>(nums.size()) - 2; ++j) {
                int total = target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == total) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // remove duplicates for left and right pointers
                        while (left < right && nums[left + 1] == nums[left])
                            ++left;
                        while (left < right && nums[right - 1] == nums[right])
                            --right;
                        ++left; --right;
                    } else if (nums[left] + nums[right] > total)
                        --right;
                    else
                        ++left;
                }
                // remove duplicates for j pointer
                while (j < nums.size() - 2 && nums[j + 1] == nums[j])
                    ++j;
            }
            // remove duplicates for i pointer
            while (i < nums.size() - 3 && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
/*
In general if k-sum : O(n^k) can be reduced to O(n^(k-1))
*/
