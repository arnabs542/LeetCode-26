// Tags: DP BFS WC236
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[] = {1, 0, 1};
        for (int obs : obstacles) {
            // dp for the lane where obstacle is present is INF
            if (obs > 0)
                dp[obs - 1] = 1e6;
            for (int x = 0; x < 3; ++x) {
                // update dp for all lanes except the one where obstacle is present
                if (x != obs - 1) {
                    dp[x] = min(dp[x], min(dp[(x + 1) % 3], dp[(x + 2) % 3]) + 1);
                }
            }
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};
/*
dp[i][x] = minimum jump to reach index i at lane x
    where x = 0, 1, 2
    
dp[i][x] =      INF if there is an obstacle at lane x
            else
                min(dp[i - 1][x], dp[i][(x + 1) % 3] + 1, dp[i][(x + 2) % 3] + 1)

dp[i][(x + 1) % 3] is same as dp[i - 1][(x + 1) % 3] if obstacle is not present at lane (x + 1) % 3
else it is INF

Base case:
dp[0][0] = 1
dp[0][1] = 0
dp[0][2] = 1
*/
