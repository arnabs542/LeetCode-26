// Tags: Array Binary-search Amazon
// Time: O(log(m*n))
// Space: O(1)
// Binary search solution
// (Also check 0036-valid-soduko)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            int i = mid/n, j = mid%n;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};

/*
Don't treat it as a 2D matrix, just treat it as one long sorted list.

n * m matrix convert to an array => matrix[i][j] => a[i * n + j]

an array convert to n * m matrix => a[x] =>matrix[x / n][x % n];
*/



// Time: O(m + n)
// Space: O(1)
// BST solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++i;
            else
                --j;
        }
        return false;
    }
};
