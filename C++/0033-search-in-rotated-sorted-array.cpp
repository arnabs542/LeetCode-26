// Time O(logn)
// Space O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;

        int left = 0;
        int right = nums.size()-1;

        while(left < right){
            int mid = left + (right-left)/2 ;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int inflect = left;
        left = 0;
        right = nums.size()-1;

        if ( target >= nums[inflect] && target <= nums[right]){
                left = inflect;
        } else {
            right = inflect-1;
        }

        //binary search

        while (left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] < target){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
            return -1;

    }
};
