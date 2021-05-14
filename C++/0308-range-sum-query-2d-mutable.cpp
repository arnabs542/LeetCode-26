// Tags: Segment-tree Binary-indexed-tree Google Premium
// Time: ctor: O(m*n)
//       update and sumRegion: O(m)
// Space: O(1)
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




// Time:  ctor: O(m*n),
//        update: O(log(m*n)),
//        query: O(log(m*n))
// Space: O(m*n)
// Segment tree solution
struct SegTreeNode {
    // segment range [(row1, col1)  (row2, col2)]
    int row1, row2, col1, col2, sum;
    // children
    SegTreeNode *c1, *c2, *c3, *c4;
    SegTreeNode(int row1, int col1, int row2, int col2): row1(row1),
        col1(col1), row2(row2), col2(col2), sum(0) {
            
        }
    
};
class NumMatrix {
    vector<vector<int>> matrix;
    SegTreeNode *root;
    SegTreeNode* buildTree(int row1, int col1, int row2, int col2) {
        if (row2 < row1 || col2 < col1)
            return nullptr;
        SegTreeNode* root = new SegTreeNode(row1, col1, row2, col2);
        if (row1 == row2 && col1 == col2) {
            root->sum = matrix[row1][col1];
            return root;
        }
        int row_mid = (row1 + row2) / 2;
        int col_mid = (col1 + col2) / 2;
        // break into 4 sub-matrices
        // first
        root->c1 = buildTree(row1, col1, row_mid, col_mid);
        // second
        root->c2 = buildTree(row1, col_mid + 1, row_mid, col2);
        // third
        root->c3 = buildTree(row_mid + 1, col1, row2, col_mid);
        // fourth
        root->c4 = buildTree(row_mid + 1, col_mid + 1, row2, col2);
        // update sum
        root->sum += root->c1 ? root->c1->sum : 0;
        root->sum += root->c2 ? root->c2->sum : 0;
        root->sum += root->c3 ? root->c3->sum : 0;
        root->sum += root->c4 ? root->c4->sum : 0;
        return root;
    }
    void updateHelper(SegTreeNode *root, int row, int col, int val) {
        if (root == nullptr || row < root->row1 || row > root->row2 ||
           col < root->col1 || col > root->col2)
            return;
        if (root->row1 == root->row2 && root->row1 == row
           && root->col1 == root->col2 && root->col1 == col) {
            root->sum = val;
            return;
        }
        updateHelper(root->c1, row, col, val);
        updateHelper(root->c2, row, col, val);
        updateHelper(root->c3, row, col, val);
        updateHelper(root->c4, row, col, val);
        root->sum = root->c1 ? root->c1->sum : 0;
        root->sum += root->c2 ? root->c2->sum : 0;
        root->sum += root->c3 ? root->c3->sum : 0;
        root->sum += root->c4 ? root->c4->sum : 0;
    }
    
    int sumRegionHelper(SegTreeNode *root, int qrow1, int qcol1, int qrow2, int qcol2) {
        // no overlap
        if (root == nullptr || qrow2 < root->row1 || qrow1 > root->row2 ||
           qcol2 < root->col1 || qcol1 > root->col2)
            return 0;
        // total overlap
        if (qrow1 <= root->row1 && qcol1 <= root->col1 && root->row2 <= qrow2
            && root->col2 <= qcol2)
            return root->sum;
        // partial overlap
        return sumRegionHelper(root->c1, qrow1, qcol1, qrow2, qcol2) +
            sumRegionHelper(root->c2, qrow1, qcol1, qrow2, qcol2) +
            sumRegionHelper(root->c3, qrow1, qcol1, qrow2, qcol2) +
            sumRegionHelper(root->c4, qrow1, qcol1, qrow2, qcol2);
    }
public:
    NumMatrix(vector<vector<int>>& matrix): matrix(matrix) {
        root = buildTree(0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
    
    void update(int row, int col, int val) {
        if (matrix[row][col] != val) {
            // matrix[row][col] = val;
            updateHelper(root, row, col, val);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRegionHelper(root, row1, col1, row2, col2);
    }
};


// To do: Optimized segment tree solution (bookmarked)
