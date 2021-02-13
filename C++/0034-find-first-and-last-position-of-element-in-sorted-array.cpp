// Tags: Array Binary-search Amazon
// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans1 = -1, ans2 = -1;
        // find leftmost
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                ans1 = mid;
                right = mid - 1;
            } else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        left = 0, right = nums.size() - 1;
        // find rightmost
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                ans2 = mid;
                left = mid + 1;
            } else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {ans1, ans2};
    }
};
/* find two points of inflection */
