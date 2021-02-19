// Tags: DP Amazon
// Time: O(n^3/k), for every i, j, t changes in steps of k - 1 = n*n*(n/(k - 1))
// Space: O(n^2 * k)
// 3D Dp
// Best Memoization template
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        vector<int> prefix(n + 1);
        // prefix[i] = sum of 0....i - 1
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(K + 1, INT_MAX)));

        function<int(int, int, int)> dp = [&](int i, int j, int m) {
            // each time we merge total piles decreases by K - 1
            // so remaining piles (total - m) should be gone
            // (assuming each K merge operation leading to 1 out of m piles)
            // ***** most important *****
            if ((j - i + 1 - m) % (K - 1) != 0)
                return INT_MAX;

            if (memo[i][j][m] != INT_MAX)
                return memo[i][j][m];
        
            if (i == j)
                return memo[i][j][m] = (m == 1) ? 0 : INT_MAX;
        
            if (m == 1)
                return memo[i][j][m] = dp(i, j, K) + prefix[j + 1] - prefix[i];
        
            // since we can merge K piles into one, each time we take (K-1) more
            // steps, we can merge them together again.
            for (int t = i; t < j; t += K - 1) {
                memo[i][j][m] = min(memo[i][j][m], dp(i, t, 1) + dp(t + 1, j, m - 1));
            }
            return memo[i][j][m];
        };

       return dp(0, n - 1, 1) == INT_MAX ? -1 : dp(0, n - 1, 1);
    }
};

/*
This is not a greedy problem:
E.g. [6,4,4,6], k = 2 -> greedy gives 42 as ans, however actual ans is 40
merge 6<->4 first then another 6<->4 10 + 10 + 20 = 40

dp[i, j, m] = minimum cost of merging piles from i to j with m piles remaining
(merging K piles at each step into 1 or removing K - 1 piles)

dp[i, j, 1] = dp[i, j, K] + (sum of piles from i to j)

dp[i, j, m] = min(dp[i, t, 1] + dp[t + 1, j, m - 1]) over i <= t < j

Base case:
dp[i, i, 1] = 0
All others = max

Everytime we merge K piles to 1 pile, so the total number of piles decrease by (K - 1)
for each merge, initially, we have j - i + 1 piles, and our target is m piles,
so the total number of decrement is (j - i + 1 - m)
(j - i + 1 - m) % (K - 1) should be 0, otherwise we cannot reach the target piles

Q: Why t jump at step K - 1?
A: We can merge K piles into one pile,
   we can't merge K + 1 piles into one pile.
   We can merge K + K - 1 piles into on pile,
   We can merge K + (K - 1) * steps piles into one pile
   (think with respect to dp[i, t, 1])
*/



// Time: O(n^3/k)
// Space: O(n^2)
// 2D Dp 
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1))
            return -1;
        vector<int> prefix(n + 1);
        // prefix[i] = sum of 0....i - 1
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = K; l <= n; ++l) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
                }
                // leaving 1, are remaining divisible by K - 1
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
       return dp[0][n - 1];
    }
};
/*
dp[i][j] means the minimum cost needed to merge stones[i] ~ stones[j]
merging as much as possible with (j - i) % (K - 1) + 1 remaining
*/
