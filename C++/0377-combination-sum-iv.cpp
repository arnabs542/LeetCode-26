// Using Backtracking: Failed Attempt
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        helper(nums, target);
        return combns;

    }
private:
    int combns = 0;
    void helper(vector<int> &nums, int target)
    {
       if (target == 0) {
            ++combns;
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] <= target)
                helper(nums, target - nums[i]);
            else
                return;
        }
    }
};

// Time: O(n*t)
// Space: O(t)
// DP Top-Down Approach
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(nums, dp, target);

    }
private:
    int helper(vector<int> &nums, vector<int> &dp, int target)
    {
        if (dp[target] != -1)
           return dp[target];

        int combns = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] <= target)
                combns += helper(nums, dp, target - nums[i]);
        }

        dp[target] = combns;
        return combns;
    }
};
