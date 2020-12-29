// Time: O(n*s)
// Space: O(n*s)
// Check Python version for comments
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target & 1)
            return false;
        target /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));
        for (auto k = 0; k <= nums.size(); ++k)
            dp[k][0] = true;
        
        for (auto k = 1; k <= nums.size(); ++k) {
            for (auto x = 1; x <= target; ++x) {
                if (x - nums[k - 1] < 0)
                    continue;
                dp[k][x] = dp[k - 1][x] | dp[k - 1][x - nums[k - 1]];
            }
        }
        return dp[nums.size()][target];
    }
};



// Time: O(n*s)
// Space: O(s)
// Check Python version for comments
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target & 1)
            return false;
        target /= 2;
        vector<int> dp (target + 1);
        dp[0] = true;
        for (auto k = 1; k <= nums.size(); ++k) {
            for (int x = target; x >= 0; --x) {
                if (x - nums[k - 1] < 0)
                    continue;
                dp[x] = dp[x] | dp[x - nums[k - 1]];
            }
        }
        return dp[target];
    }
};
