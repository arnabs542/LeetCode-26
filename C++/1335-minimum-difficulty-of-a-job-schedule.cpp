// Tags: Dp Amazon
// Time complexity O(nnd)
// Space complexity O(n)
class Solution {
public:
    int minDifficulty(vector<int>& A, int D) {
        int inf = 1e8, n = A.size();
        if (n < D)
            return -1;
        vector<int> dp(n + 1, inf);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                // reset dp[i] calculated for d - 1 days
                dp[i] = inf; 
                int maxd = 0;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};

/*
dp[i] denotes the minimum difficulty of a job schedule for A[i:], done
in d days

dp[i] = (i <= j <= n - d) MIN (maxd(upto j) + dp[j + 1])

maxd is the difficulty for finishing A[0:j] jobs on first day
dp[j + 1] is the minimum difficulty for finishing the rest of the
jobs i.e A[j + 1:] in d - 1 days.

(we take n - d so that there are atleast d number of jobs when i = n - d)

Base case:
dp[n] = 0, helps in updating dp array during day 1,
making dp[j + 1] = 0 in the last iter for each index i.
*/
