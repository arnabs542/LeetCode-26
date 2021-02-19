// Tags: Array Greedy Amazon DP
// Time: O(n)
// Space: O(1)
// greedy solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, n = prices.size(), profit = 0;
        // there has to be atleast 1 more day left to sell
        while (i < n - 1) {
            // smallest in consecutive decreasing prices
            // = for cases like [3,3]
            while (i < n - 1 && prices[i + 1] <= prices[i])
                ++i;
            int buy = prices[i];
            // largest in consecutive increasing prices
            while (i < n - 1 && prices[i + 1] > prices[i])
                ++i;
            int sell = prices[i];
            profit += sell - buy; 
        }
        return profit;
    }
};
/*
From this observation, from day X, the buying day will be
the last continuous day that the price is smallest. Then,
the selling day will be the last continuous day that the
price is biggest.
*/


// Second way: DP (similar to 0309-best-time-to-buy-and-sell-stock-with-cooldown)
// Also O(n), money in hand approach
