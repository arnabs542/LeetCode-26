// Tags: Array Greedy Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, n = prices.size(), profit = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i + 1] <= prices[i])
                ++i;
            int buy = prices[i];
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
