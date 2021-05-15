// Tags:
// Time: ctor: O(m*n)
//       update and sumRegion: O(m)
// Array of prefix sums
class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // convert each row into a prefix sum array
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        this->matrix = matrix;
    }
    
    void update(int row, int col, int val) {
        // capture original value
        int orig = matrix[row][col];
        // if not the first column
        if (col != 0)
            orig -= matrix[row][col - 1];
        // calculate the difference
        int diff = val - orig;
        // propogate the difference
        for (int j = col; j < matrix[row].size(); ++j)
            matrix[row][j] += diff;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        // iterate each row in the range [row1, row2]
        for (int i = row1; i <= row2; ++i) {
            sum += matrix[i][col2];
            // if not the first column
            if (col1 != 0)
                sum -= matrix[i][col1 - 1];
        }
        return sum;
    }
};
