// Tags: Greedy Sort WC224
// Time: O(m*nlogn)
// Space: O(n)
// Combination of 0085-maximal-rectangle and
// 0084-largest-rectangle-in-histogram
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
            
            vector<int> ordHeights(heights);
            sort(ordHeights.begin(), ordHeights.end());
            // now the array behaves like an ordered increasing stack
            for (int j = 0; j < n; ++j) {
                // similar to heights[idx] (i - st.top() - 1);
                res = max(res, ordHeights[j]*(n - j));
            }
        }
        return res;
    }
};
/*
Can save space by recording heights array values
in each row of the matrix itself.
*/
