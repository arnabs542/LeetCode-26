// Tags: Array Binary-search Amazon
// Time O(logn)
// Space O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        // index of smallest number (point of inflection)
        int inflect = -1;
        // search looks like
        // [T T T F F] (rotated) or 
        // [F F F F F] (already sorted)
        // we are looking for first false
        while (left <= right) {
            int mid = left + (right - left)/2;
            // (compare with last element)
            if (nums[mid] > nums[nums.size() - 1]) {
                // T
                left = mid + 1;
            } else {
                // F (region of interest)
                inflect = mid;
                right = mid - 1;
            }
        }
        
        left = 0;
        right = nums.size() - 1;
        if (target >= nums[inflect] && target <= nums[right]) {
            // right part
            left = inflect;
        } else {
            // left part
            right = inflect - 1;
        }

        // usual binary search
        while (left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
