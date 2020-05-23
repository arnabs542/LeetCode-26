// Time: O(mn)
// Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool first_row_zero = false;

        for (int col = 0; col < n; ++col) {
            if (matrix[0][col] == 0)
                first_row_zero = true;
        }

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = 1; row < m; ++row) {
            bool contains_zero = false;
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    contains_zero = true;
                    break;
                }
            }

            for (int col = 0; col < n; ++col) {
                if(contains_zero || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        if (first_row_zero) {
            for (int col = 0; col < n; ++col)
                matrix[0][col] = 0;
        }

    }
};

// Time: O(mn)
// Space: O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<bool> column_zero(n);

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    column_zero[col] = true;
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            bool contains_zero = false;
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    contains_zero = true;
                    break;
                }
            }

            for (int col = 0; col < n; ++col) {
                if(contains_zero || column_zero[col]) {
                    matrix[row][col] = 0;
                }
            }
        }

    }
};






// Time: O(mn)
// Space: O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<bool> row_zero(m);
        vector<bool> column_zero(n);

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] == 0) {
                    row_zero[row] = true;
                    column_zero[col] = true;
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row_zero[row] || column_zero[col]) {
                    matrix[row][col] = 0;
                }
            }
        }

    }
};
