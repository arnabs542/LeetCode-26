// Time:  O(m * n)
// Space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j)
                res.push_back(matrix[top][j]);

            for (int i = top + 1; i < bottom; ++i)
                res.push_back(matrix[i][right]);

            for (int j = right; j >= left; --j)
                if (top < bottom) // skip for single row
                res.push_back(matrix[bottom][j]);

            for (int i = bottom - 1; i > top; --i)
                if (left < right) // skip for single column
                res.push_back(matrix[i][left]);

            ++left, ++top, --right, --bottom;
        }
        return res;
    }
};
