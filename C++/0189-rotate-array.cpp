// Tags: Array Top-interview
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        // Reverse the last k numbers
        reverse(nums.begin() + n - k, nums.end());
        
        // Reverse the first n - k numbers
        reverse(nums.begin(), nums.begin() + n - k);
        
        // Reverse all the numbers
        reverse(nums.begin(), nums.end());
    }
};
