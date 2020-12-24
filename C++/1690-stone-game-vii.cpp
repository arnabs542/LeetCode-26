// Tags: DP WC219
// Time: O(n^2)
// Space: O(n^2)
// Bottom-up Dp, tabulation
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> psum(n + 1);
        // psum[i] denotes sum pre to i ie upto i - 1;
        // psum[0] = 0;
        // (prefix array is defined this way so that i - 1 for
        //  i = 0 is not undefined)
        for (auto i = 0; i < n; ++i)
            psum[i + 1] = psum[i] + stones[i];
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(psum[j + 1] - psum[i + 1] - dp[i + 1][j], psum[j] - psum[i] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

/*
Let dp[i][j] be the maximum difference the first player can get if the players play on A[i..j].
dp[i][j] = max(
                sum(i + 1, j) - dp[i + 1][j],   // if the first player choose `A[i]`
                sum(i, j - 1) - dp[i][j - 1]    // if the first player choose `A[j]`
              )

Let say, if it's our turn on [i,j] and we took stones[i], we will add to our scores an amount of 
amount = sum[j + 1] - sum[i + 1]. In the next turn [i+1,j], the next player will play optimally 
and get an optimal score difference dp[i+1][j] = his_scores - my_scores. So, in the interval [i,j],
the new difference will be dp[i][j] = my_scores + amount - his_scores, that can be write as
dp[i][j] = amount - (his_scores - my_scores). 
That is dp[i][j] = sums[j+1] - sums[i+1] - dp[i+1][j] if we took stones[i].
*/



// Time: O(n^2)
// Space: O(logn)
// Top-down Dp, memoization
class Solution {
    array<array<int, 10001>, 1001> dp;
public:
    int stoneGameVII(vector<int>& stones) {
        return dfs(stones, 0, stones.size() - 1, accumulate(stones.begin(), stones.end(), 0));
    }
    
    int dfs(vector<int> &s, int i, int j, int sum) {
        // no elements left after s[i] is removed, therefore gain = 0
        if (i == j)
            return 0;
        // remove s[i] or remove s[j]
        // the next dfs() denotes maximum gain in si+1....j or si....sj-1 (second player's turn)
        return dp[i][j] ? dp[i][j] : dp[i][j] = max(sum - s[i] - dfs(s, i + 1, j, sum - s[i]), sum - s[j] - dfs(s, i, j - 1, sum - s[j]));
    }
};
/*
We are exploring all options such that the first player to start the game wins.

Let dp[i][j] be the maximum difference the first player can get if the players play on A[i..j].

You need to think of the problem of maximizing the gain of each player. The only way Bob can reduce the difference is to select the max possible value from what he can get from the remaining.
So it doesnot matter who is picking, they will try to get the max difference as possible.
In this case, if Bob selects 5, he has a gain of 7 and if selecting 4, he has a gain of 6

(If Bob removes 5, he will get 3 + 1 + 4, then Alice will remove either 3 or 4 to get 1 + (3 or 4), 
but Bob will get back 3 or 4 by removing 1, so the total difference gain for Bob will be 
3 + 1 + 4 - (1 + (3 or 4) ) + (3 or 4) = 7 which is (total gain(Bob) - total gain(Alice)) starting from second round.
On the other hand if Bob removes 4, he will get 5 + 3 + 1, then Alice will remove 1 to 
get 5 + 3, and Bob can get back 5, yielding a total difference gain of 5 + 3 + 1 - (5 + 3) + 5 = 6
So removing 5 is the better solution here)

I guess the takeaway message here is, more points in one step does not lead to more points in the end,
and that's why dynamic programming, instead of greedy, needs to be used for this problem

Suppose n=5, then Alice's gain is a1+a3+a5 (odd rounds) where a1 means the 1st round's gain for Alice. 
Bob's gain is b2+b4 (even rounds). The final difference is (a1+a3+a5)-(b2+b4) which can be rewritten as 
a1-(b2-(a3-(b4-a5))). If we realize that a1>b2>a3>b4>a5, we know this is actually a recursive pattern. 
The optimal strategy for both players is to maximize my_current_round_gain - subproblem_difference. 
Alice wants to maximize a1-subproblem, so Alice wants to maximize a3-subproblem due to the 
double negation. The same for Bob. Bob wants to minimize a1-subproblem, so Bob wants to maximize 
b2-subproblem, then maximize b4-subproblem due to double negation. 
This insight will help reduce the complexity a lot since we only need one DP instead of two
*/
