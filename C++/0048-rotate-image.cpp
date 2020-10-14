// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        // main-diagonal mirror
        // iterating upper triangular half, row by row
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // vertical mirror
        // iterating left half, row by row
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n/2; ++j)
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};
