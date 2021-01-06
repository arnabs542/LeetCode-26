// Tags: Amazon DP Array
// Time: O(kn^2)
// Space: O(kn)
// Time limit exceeded
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size()));
        for (int k = 1; k <= 2; ++k) {
            dp[k][1] = max(prices[1] - prices[0], 0);
            for (auto i = 2; i < prices.size(); ++i) {
                int maxa = -prices[0]; // bought on 0th day
                for (int j = 1; j <= i - 1; ++j) {
                    // bought on jth day
                    maxa = max(dp[k - 1][j - 1] - prices[j], maxa);
                }
                dp[k][i] = max(dp[k][i - 1], maxa + prices[i]);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
/*
dp[k, i] = maximum profit achieved on ith day, doing k transactions
dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), 
           for j=[0..i-1]
Base Case:
dp[k, 0] = 0
dp[k, 1] = max(prices[1] - prices[0], 0)
*/



// Time: O(kn^2)
// Space: O(kn)
// Time limit exceeded (1-indexed dp array)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size() + 1));
        for (int k = 1; k <= 2; ++k) {
            dp[k][2] = max(prices[1] - prices[0], 0);
            for (auto i = 3; i <= prices.size(); ++i) {
                for (int j = 1; j <= i - 1; ++j) {
                   dp[k][i] = max({dp[k][i], dp[k][i - 1], dp[k - 1][j - 1] - prices[j - 1] + prices[i - 1]});
                }
            }
        }
        return dp[2][prices.size()];
    }
};



// Time: O(kn)
// Space: O(kn)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size()));
        for (int k = 1; k <= 2; ++k) {
            dp[k][1] = max(prices[1] - prices[0], 0);
            int maxa = -prices[0];
            for (auto i = 2; i < prices.size(); ++i) {
                maxa = max(dp[k - 1][i - 1 - 1] - prices[i - 1], maxa);
                dp[k][i] = max(dp[k][i - 1], maxa + prices[i]);
            }
        }
        return dp[2][prices.size() - 1];
    }
};
/* We don't have to repeatedly calculate maxa.
   maxa can be made to store the maximum (dp[k - 1][j - 1] - prices[j]) upto
   j = i - 2
*/


// To do: O(k) space solution: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
