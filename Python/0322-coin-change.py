# Time:  O(n * k), n is the number of coins, k is the amount of money
# Space: O(k)

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = 0x7fffffff # using float("inf") would be slower
        opt = [INF] * (amount + 1)
        # amounts = [INF for _ in range(amount + 1)]
        opt[0] = 0

        for x in range(amount + 1):
            for coin in coins:
                if coin <= x:
                    opt[x] = min(opt[x], opt[x - coin] + 1)

        return opt[amount] if opt[amount] != INF else -1


"""""
Notes:
opt[s] - minimum number of coins needed to make change for
amount s using coin dominations [c0,......, cn-1]

opt[s] = opt[s-ci] + 1 where ci is the last coin chosen

to find ci we choose minimum among the all denominations c0, c1,
c2,.......cn-1.

=> opt[s] = Min(i) opt[s-ci] + 1  s.t s-ci >= 0

Can also be solved using opt[k, s] = MIN( opt[k, s - ck]), opt[k-1, s] ) which has O(n*k) space requirements.

"""""



# Time:  O(n * k), n is the number of coins, k is the amount of money
# Space: O(n * k)
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        # inf since we are taking min in recurrence relation
        dp = [[float("inf")]*(amount+1) for _ in range(n+1)]

        for k in range(n+1):
            for x in range(amount+1):
                if k == 0:
                    continue
                if x == 0:
                    dp[k][x] = 0
                    continue
                if coins[k-1] > x:
                    dp[k][x] = dp[k-1][x]
                else:
                    dp[k][x] = min(dp[k-1][x], dp[k][x-coins[k-1]] + 1)
        return -1 if dp[n][amount] == float("inf") else dp[n][amount]

"""
opt[k, x] = min(opt[k-1, x], opt[k, x-dk] + 1)

Base case:
opt[k, 0] = 0

"""
