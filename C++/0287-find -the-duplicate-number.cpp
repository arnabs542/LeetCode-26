// Tags: Array Two-pointers Binary-search
// Time:  O(nlogn), search logn times
// Space: O(1)
// Binary search method (search space)
// Check Python version for comments
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int count = 0;
            for (auto n: nums)
                if (n <= mid)
                    ++count;
            if (count > mid) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
