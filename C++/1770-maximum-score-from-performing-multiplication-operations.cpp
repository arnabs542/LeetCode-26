// Tags: WC229 DP
// Time: O(m^2)
// Space: O(m^2)
// Top-down Dp, memoization
class Solution {
    int memo[1001][1001] = {};
    int dp(vector<int>& nums, vector<int>& mult, int i, int j) {
        int n = nums.size(), m = mult.size();
        int index = (i - 0) + (n - 1 - j);
        // all multipliers used
        if (index == m)
            return 0;
        if (!memo[i][j - (n - m)]) {
            memo[i][j - (n - m)] = max(nums[i]*mult[index] + dp(nums, mult, i + 1, j),
                        nums[j]*mult[index] + dp(nums, mult, i, j - 1));
        }
        return memo[i][j - (n - m)];
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return dp(nums, multipliers, 0, nums.size() - 1);
    }
};

/*
dp[i, j] = maximum score achieved in nums i.....j
At each time, we have 2 choices, take either left element or right element
and return the max of the two choices.

dp[i, j] = max(nums[i]*mult[idx] + dp[i + 1, j], nums[j]*mult[idx] + dp[i, j - 1])

where idx = index to next multipliers to use
          = how much left pointer is moved + how much right pointer is moved
          = (i - 0) + (n - 1 - j)
            (goes from 0 to m - 1)
=> index information is made self-contained
        
if idx = m i.e no more remaining multipliers,
    dp[i][j] = 0


The hardest part is to manage space as dp[n][n] will lead to out of memory

Observation:
The range of i is at most [0, m), all elements taken from left
    => m slots req to store i values
and the range of j is at most [n - m, n), all elements taken from right
    => m slots req to store j values
    
So lets shift the start of right pointer from n - m to 0 (normalize it).
    => dp[i][j] becomes dp[i][j - (n - m)]

Now, we just need dp[m][m] instead of dp[n][n], saves a lot of space.
*/
