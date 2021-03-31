// Tags: DP Amazon
// Time: O(kn)
// Space: O(kn)
// Same as 0123-best-time-to-buy-and-sell-stock-iii
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(K + 1, vector<int>(prices.size()));
        for (int k = 1; k <= K; ++k) {
            dp[k][1] = max(prices[1] - prices[0], 0);
            // stores max {dp[k - 1][j - 1] - prices[j]} upto j = i - 2
            int maxa = -prices[0];
            for (auto i = 2; i < prices.size(); ++i) {
                maxa = max(dp[k - 1][i - 1 - 1] - prices[i - 1], maxa);
                dp[k][i] = max(dp[k][i - 1], maxa + prices[i]);
            }
        }
        return dp[K][prices.size() - 1];
    }
};
/*
Base case:
dp[k][0] = 0
dp[k][1] = min(0, prices[1] - prices[0])
*/
