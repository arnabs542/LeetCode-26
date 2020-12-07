// Using Backtracking: Failed Attempt, Time limit exceeded
// In worst n^h paths are possible, n is length of nums, h is height of tree
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
        }
    }
};

// Time: O(n*t)
// Space: O(t), for nums[i] = 1 at each level
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

/*
opt[t] = sigma nums[0] <= n <= nums[-1] (opt[t-n])
*/



// Time: O(nlogn + n * t), t is the value of target.
// Space: O(t)
// DP Bottom-Up Approach
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // number of ways can't be negative
        vector<uint32_t> dp(target + 1, 0);

        // base case
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i)
            for (const auto &num: nums)
                if (num <= i)
                    dp[i] += dp[i - num];
                else
                    break;
        return dp[target];
    }
};

/*
Here we are talking about permutations not combinations.
This can't be done using knapsack dp format which only considers
combinations.
(Look at coin change O(n * k) and coin change 2 O(n) space)
*/
