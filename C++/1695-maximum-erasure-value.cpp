// Tags: Two-pointers WC220
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for (int left = 0, right = 0, sum = 0; right < nums.size(); ++right) {
            while (s.count(nums[right])) {
                s.erase(nums[left]);
                sum -= nums[left];
                ++left;
            }
            s.insert(nums[right]);
            sum += nums[right];
            res = max(res, sum);
        }
        return res;
    }
};
