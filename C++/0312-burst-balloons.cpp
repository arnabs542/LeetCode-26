// Tags: DP
// Time:  O(n^3)
// Space: O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + 
            nums[i - 1]*nums[k]*nums[j  + 1]);
                }
            }
        }
        return dp[1][n];
    }
};

/*
Let dp[i, j] = maximum coins gained from burstring all balloons between
index i and j in the original array, i and j are included.

dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + 
            nums[i - 1]*nums[k]*nums[j  + 1]) for i<=k<=j
where k be the index of the last baloon to be burst between i & j
(all balloons in [i, k - 1] & dp[k + 1, j] are already burst)

Base Case:
dp[i, i - 1] = dp[i + 1, i] = 0 as i should be <= j, which isn't the case
when k = i or j
*/
