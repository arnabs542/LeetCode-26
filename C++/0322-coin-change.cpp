// DP: Top down approach
// Time: O(amount*n)
// Space: O(n), due to memoization table.
// Also maximum height of tree is n for denomination of 1
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
