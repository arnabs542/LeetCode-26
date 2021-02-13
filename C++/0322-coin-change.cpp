// Tags: DP Amazon
// Dp: Top-down approach
// Time: O(amount*n)
// Space: O(amount), due to memoization table.
// Also maximum height of tree is amount for denomination of 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> opt(amount+1, 0);
        return helper(coins, amount, opt);
    }

private:
    int helper(vector<int> &coins, int amount, vector<int> &opt) {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        if (opt[amount] != 0)
            return opt[amount];
        int min_res = numeric_limits<int>::max();
        for (auto coin: coins) {
            int res = helper(coins, amount - coin, opt);
            if (res >= 0)
                min_res = min(min_res, res);
        }
        opt[amount] = (min_res == numeric_limits<int>::max()) ? -1 : min_res + 1;
        return opt[amount];
    }
};
/*
f(s) represents the minimum coins needed for amount s
f(s) = min(F(s - ci) + 1)
    s.t s-ci >= 0
f(s) = 0, if s=0
*/



// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(k)
// Bottom-up Dp, tabulation
// (Similar to 0377-combination-sum-iv, taking permutations)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // numeric_limits<int>::max() not used to prevent integer buffer overflow
        int INF = amount + 1;
        vector<int> dp(amount + 1, INF);

        dp[0] = 0;

        for (int x = 1; x <= amount; ++x) {
            for (const auto &coin: coins) {
                if (coin <= x)
                    dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
        return (dp[amount] == INF) ? -1 : dp[amount];
    }
};
/*
Note: This approach only possible as we may have an infinite number
    of each kind of coin, as per the question.
    (and we only care about minimum or for target 5 if 1 + 4 and 4 + 1
    considered as separate permutations it doesn't make our result wrong)

opt[s] - minimum number of coins needed to make change for
amount s using coin dominations [c0,......, cn-1]

opt[s] = opt[s-ci] + 1 where ci is the last coin chosen

to find ci we choose minimum among the all denominations c0, c1,
c2,.......cn-1.

=> opt[s] = Min(i) opt[s-ci] + 1  s.t s-ci >= 0

Can also be solved using opt[k, s] = MIN( opt[k, s - ck] + 1, opt[k-1, s] ) 
which has O(n*k) space requirements.
*/



// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(n * k)
// Knapsack style Dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int inf = 1e9;
        // inf since we are taking min in recurrence relation
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, inf));
        for (int k = 0; k <= n; ++k) {
            for (int x = 0; x <= amount; ++x) {
                if (k == 0)
                    continue;
                if (x == 0) {
                    dp[k][x] = 0;
                    continue;
                }
                // integer overflow here in C++ (INT_MAX + 1)
                // temp sol: take inf == amount + 1 or 1e9
                if (coins[k - 1] > x)
                    dp[k][x] = dp[k - 1][x];
                else
                    dp[k][x] = min(dp[k - 1][x], dp[k][x - coins[k - 1]] + 1);
            }
        }
        return dp[n][amount] == inf ? -1 : dp[n][amount];
    }
};
/*
opt[k, x] = min(opt[k-1, x], opt[k, x-dk] + 1)

Base case:
opt[k, 0] = 0

Note: initial value is taken inf so that min(opt[0, x], opt[1, x - d1] + 1)
gives 1 not 0

opt[k, x] = opt[k - 1, x] if dk > x, we can't pick this coin ever
*/
