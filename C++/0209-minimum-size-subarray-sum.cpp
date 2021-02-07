// Tags: Array Sliding-window Binary-search Amazon
// Time: O(n), each element will be visited by l and
//       r for at most once
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, n = nums.size();
        int res = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            // update res only when sum becomes >= s
            while (sum >= s) {
                res = min(res, r - l);
                sum -=nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

/*
First we move r until we get a sum >= s, 
then we move l to the right until sum < s
*/

// To do: O(nlogn) Binary search solution
