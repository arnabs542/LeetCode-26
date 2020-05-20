// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
      if (matrix.empty())
      return {};

      vector<vector<int>> res;
      const auto m =  matrix.size(), n = matrix[0].size();
      vector<vector<int>> pacific(m, vector<int>(n));
      vector<vector<int>> atlantic(m, vector<int>(n));


      for (int i = 0; i < m; ++i) {
        dfs(matrix, i, 0, numeric_limits<int>::min(), pacific);
        dfs(matrix, i, n-1, numeric_limits<int>::min(), atlantic);
      }

      for (int j = 0; j < n; ++j) {
        dfs(matrix, 0, j, numeric_limits<int>::min(), pacific);
        dfs(matrix, m-1, j, numeric_limits<int>::min(), atlantic);
      }

      for (int i=0; i < m; i++) {
           for (int j=0; j < n; j++) {
               if (pacific[i][j] == 1 && atlantic[i][j] == 1){
                   res.emplace_back(vector<int> {i,j});
               }
           }
       }
       return res;
    }

        void dfs(vector<vector<int>> &matrix, int row, int col, int prevVal, vector<vector<int>> &ocean)
        {
            // check the necessary conditions
            if (row < 0 || col < 0 || row > matrix.size() - 1 || col > matrix[0].size() - 1)
                return;
            else if (matrix[row][col] < prevVal)
                return;
            else if (ocean[row][col]  == 1 )
                return;

            // process cell
            ocean[row][col] = 1;


            // call dfs as needed
            dfs(matrix, row - 1, col, matrix[row][col], ocean);
            dfs(matrix, row + 1, col, matrix[row][col], ocean);
            dfs(matrix, row, col - 1, matrix[row][col], ocean);
            dfs(matrix, row, col + 1, matrix[row][col], ocean);

        }
    };
