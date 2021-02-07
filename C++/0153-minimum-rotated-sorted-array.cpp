// Time O(log n)
// Space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0];
        int left = 0, right = nums.size();
        int ans = -1;
        // search looks like
        // [T T T F F] (rotated) or 
        // [F F F F F] (already sorted)
        // we are looking for first false
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return nums[ans];
    }
};
