// Tags: DP Amazon
// Time: O(n*m)
// Space: O(m)
// Knapsack like Dp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int k = 1; k <= coins.size(); ++k) {
            for (int x = 1; x <= amount; ++x) {
                if (coins[k - 1] <= x)
                    dp[x] = dp[x - coins[k - 1]] + dp[x];
            }
        }
        return dp[amount];
    }
};
/*
Unlike 0377-combination-sum-iv (& coin-change O(k) space), 
here we are talking about combinations not permutations
opt[k, s] = opt[k, s - ck] + opt[k-1, s], where k represent 1,....,k
denominations and amount s.

outer loop of coins gives combinations similar to knapsack whereas
inner loop of coins gives permutations as req in combination iv
(This is exactly same as Knapsack problem with O(n) space &
coin change O(n * k) solution)
(Knapsack dp problem considers combinations not permutations)
*/
