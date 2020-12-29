// Tags: DP DFS
// Time: O(S*n)
// Space: O(logn)
// Top-down Dp, Memoization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<string, int> memo;
        return helper(nums, S, memo, 0, 0);
    }
    
    int helper(vector<int> &nums, int target, unordered_map<string, int> &memo, int idx, int cur) {
        string key = to_string(idx) + " " + to_string(cur);
        if (memo.count(key))
            return memo[key];
        if (idx == nums.size() && cur == target)
            return 1;
        if (idx == nums.size())
            return 0;
        int pos = helper(nums, target, memo, idx + 1, cur + nums[idx]);
        int neg = helper(nums, target, memo, idx + 1, cur - nums[idx]);
        memo[key] = pos + neg;
        return pos + neg;
    }
};



// Time: O(n*S)
// Space: O(S)
// Bottom-up Dp, Tabulation
class Solution {
    int subsetSum(vector<int> &nums, int target) {
    vector<int> dp(target + 1);
    // dp[k, x] = dp[k - 1, x] + dp[k - 1, x - xk]
    dp[0] = 1;
    // for (int k = 1; k <= nums.size(); ++k) {
    //     for (int x = target; x >= 0; --x) {
    //         if (x - nums[k - 1] < 0)
    //             continue;
    //         dp[x] = dp[x] + dp[x - nums[k - 1]];
    //     }
    // }
    for (auto n: nums)
        for (int x = target; x >= n; --x)
            dp[x] += dp[x - n];
    return dp[target];
}

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
    }
};

/*
The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and
the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)

So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Here target + sum(nums) must be even
We can use that fact to quickly identify inputs that do not have a solution

Also is sum(nums) < target, we don't have a solution
*/



// Time: O(2^n), number of leaves (paths)
// Space: O(logn)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, S, 0, 0);
    }
    
    int helper(vector<int> &nums, int target, int idx, int cur) {
        if (idx == nums.size() && cur == target)
            return 1;
        if (idx == nums.size())
            return 0;
        int pos = helper(nums, target, idx + 1, cur + nums[idx]);
        int neg = helper(nums, target, idx + 1, cur - nums[idx]);
        return pos + neg;
    }
};
