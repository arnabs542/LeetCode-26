# Time: O(n)
# Space: O(1)

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            for i in range(1, amount + 1):
                if coin <= i:
                    dp[i] += dp[i - coin]
        return dp[amount]

# Notes:
# Unlike combination sum iv, here we are talking about combinations
# not permutations
# opt[k, s] = opt[k, s - ck] + opt[k-1, s], where k represent 1,....,k
# denominations and amount s.
#
# outer loop of coins gives combinations similar to knapsack whereas
# inner loop of coins gives permutations as req in combination iv
