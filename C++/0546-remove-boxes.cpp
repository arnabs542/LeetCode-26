// Tags: DP Amazon
// Time:  O(n^4), for each cell i, j, k, we iterate i...j to find m
// Space: O(n^3)
// Top-down Dp, Memoization
class Solution {
    int helper(const vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if (i > j)
            return 0;
        if (dp[i][j][k])
            return dp[i][j][k];
        
        auto& orig = dp[i][j][k];
        // count consecutive boxes of same color as original ith box (needed for both choices)
        // (get current ith box & add count to original value of k)
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; ++i, ++k);
        
        // choice 1: remove the current ith box
        // (cur k + 1)*(cur k + 1) + dp[cur i + 1, j, 0]
        int res = (k + 1)*(k + 1) + helper(boxes, i + 1, j, 0, dp);
        
        // choice 2: attach current ith box to other boxes of same color
        // max over i < m <= j dp[cur i + 1, m, 0] + dp[m, j, cur k + 1]
        for (int m = i + 1; m <= j; ++m) {
            if (boxes[i] == boxes[m])
                res = max(res, helper(boxes, i + 1, m - 1, 0, dp) + helper(boxes, m, j, k + 1, dp));
        }
        // dp[orig i, j, orig k] = dp[cur i, j, cur k]
        orig = res;
        return res;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] {};
        return helper(boxes, 0, boxes.size() - 1, 0, dp);
    }
};

/*
Intuition:
dp(i, j) = maximum points possible by removing boxes of the subarray [i, j]
Like 0312-burst-balloons, the definition of the subproblem is not self
contained & its solution relies on information external to subproblem
itself.

Solution:
Modify the definition of the problem to absorb the external information
so that the new one is self-contained.

dp(i, j, k) which denotes the maximum points possible by removing the boxes
of subarray [i, j] with given k boxes attached to its left of the same color
as boxes[i].

Base Case:
dp[i, i - 1, k] = 0, no boxes so no points
dp[i, i, k] = (k + 1)*(k + 1), only one box left in the subarray but we've already
                               got k boxes of the same color attached to its left

dp[i, j, k] = 
    if we remove boxes[i],
        (k + 1)*(k + 1) + dp[i + 1, j, 0]
        (k boxes are actually external to [i, j] but absorbed in definiton making
         it self-contained)

    if we attach boxes[i] to other box of same color boxes[m]
        dp[i + 1, m - 1, 0] + dp[m, j, k + 1]
            where i < m <= j && boxes[i] == boxes[m]
        (k + 1 boxes are actually external to [m, j] but absorded in definition
         making it self-contained)
*/


// To dp: Bottom-up solution
