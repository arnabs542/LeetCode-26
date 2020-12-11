// Tags: Amazon DP
// DP using two colums
// Time: O(m * n)
// Space: O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> pre(n, 0), cur(n, 0);
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    cur[j] = 1;
                    if (i > 0 && j > 0)
                        cur[j] += min(cur[j - 1], min(pre[j - 1], pre[j]));
                } else {
                    // different from python solution
                    cur[j] = 0;
                }
                result = max(result, cur[j]);
            }
            pre = cur;
            // fill(cur.begin(), cur.end(), 0);
        }
        return result*result;
    }
};

/*
1 1 1 0
1 1 1 1
1 1 1 1
1 1 1
*/
