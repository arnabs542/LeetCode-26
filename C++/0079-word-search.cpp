// Time:  O(m * n * l)
// Space: O(l)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited (rows, vector<bool> (cols, false));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (searchWord(board, word, 0, i, j, visited))
                    return true;
        return false;
    }

    bool searchWord(vector<vector<char>> &board, string word, int cur, int i, int j, vector<vector<bool>> &visited)
    {
        if (cur == word.length())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[cur] )
            return false;

        visited[i][j] = true;

        bool result = (searchWord(board, word, cur + 1, i, j + 1, visited) ||
            searchWord(board, word, cur + 1, i, j - 1, visited) ||
            searchWord(board, word, cur + 1, i + 1, j, visited) ||
            searchWord(board, word, cur + 1, i - 1, j, visited));

        visited[i][j] = false;

        return result;

    }
};
