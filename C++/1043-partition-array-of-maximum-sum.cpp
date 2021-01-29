// Tags: DP Amazon
// Time: O(n*k)
// Space: O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            int cur_max = 0;
            for (int l = 1; l <= k && i - l + 1 >= 0; ++l) {
                cur_max = max(cur_max, arr[i - l + 1]);
                dp[i] = max(dp[i], (i >= l ? dp[i - l] : 0) + cur_max*l);
            }
        }
        return dp[arr.size() - 1];
    }
};
/*
dp[i] = maximum sum we can get for the array [0......i]

We will try to change k last numbers separately to the maximum
of them.

dp[i] = max(dp[i - l] + max_num*l) over 1 <= l <= k
*/
