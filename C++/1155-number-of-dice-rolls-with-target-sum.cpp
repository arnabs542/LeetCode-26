// Tags: DP Amazon
// Time: O(d*target*f)
// Space: O(d*target)
// Unlike 0377-combination-sum-iv, we want to restrict
// the number of elements to k
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(d + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int k = 1; k <= d; ++k) {
            for (int x = 1; x <= target; ++x) {
                for (int num = 1; num <= f; ++num)
                    if (num <= x)
                        dp[k][x] = (dp[k][x] + dp[k - 1][x - num]) % mod;
                    else
                        break;
            }
        }
        return dp[d][target];
    }
};

/*
dp[k][x] = number of possible ways to achieve total sum x using d dices

Base cases:
dp[1][1] = dp[1][2] = dp[1][3] ...... dp[1][f] = 1

e.g. k = 2, f = 6, target = 7
          x
    0 1 2 3 4 5 6 7
  0 1 0 0 0 0 0 0 0
k 1 0 1 1 1 1 1 1 0
  2 0 0 1 2 3 4 5 6

We make dp[0][0] = 1 as it helps use in defining the base cases without
explicitly doing so.
*/



// Time: O(d*target*f)
// Space: O(target)
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int k = 1; k <= d; ++k) {
            // first reset all values in this row
            dp[k % 2] = vector<int>(target + 1);
            for (int x = 1; x <= target; ++x) {
                for (int num = 1; num <= f; ++num)
                    if (num <= x)
                        dp[k % 2][x] = (dp[k % 2][x] + dp[(k - 1) % 2][x - num]) % mod;
                    else
                        break;
            }
        }
        return dp[d % 2][target];
    }
};
