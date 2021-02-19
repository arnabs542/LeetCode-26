// Tags: Greedy Amazon
// Time: O(m*n)
// Space: O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        // column 0 filled with all 1's (toggling rows, if needed)
        int res = (1 << (n - 1))*m;
        for (int j = 1; j < n; ++j) {
            // score due to current column j
            int cur = 0;
            for (int i = 0; i < m; ++i) {
                // both are zeros, if row is toggled
                // both are ones, if row is not toggled
                cur += A[i][j] == A[i][0];
            }
            // if m - cur > cur, we can toggle this column
            res += max(cur, m - cur) * 1 << (n - 1 - j);
        }
        return res;
    }
};
/*
1. A[i][0] is worth 1 << (N - 1) points, more than the sum of
(A[i][1] + .. + A[i][N-1]). So we toggle all A[i][0] to 1, here I toggle
all lines (rows) for A[i][0] = 0.

2. A[i][j] is worth 1 << (N - 1 - j)
For every col, I count the current number of 1s.
After step 1, A[i][j] becomes 1 if A[i][j] == A[i][0].
if M - cur > cur, we can toggle this column to get more 1s.
max(cur, M - cur) will be the maximum number of 1s that we can get.

E.g.
[[0,0,1,1],
 [1,0,1,0],
 [1,1,0,0]]
 
Toggle -> 1st row, 3rd col (m - cur > cur), 4th col (m - cur > cur)
 
[[1,1,1,1],
 [1,0,0,1],
 [1,1,1,1]]
*/
