// Tags: Backtracking Amazon
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

    bool searchWord(vector<vector<char>> &board, string word, int cur, int i, int j,
        vector<vector<bool>> &visited)
    {
        if (cur == word.length())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]
            || board[i][j] != word[cur] )
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



// Time:  O(m * n * l)
// Space: O(l) where l = length of word, due to recursion
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int cur_pos)
    {
        if (cur_pos == word.length())
            return true;

        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1)
            return false;

        if (word[cur_pos] != board[i][j])
            return false;

        board[i][j] = '#';

        vector<pair<int, int>> iters {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto &iter: iters) {
            if (dfs(board, word, i + iter.first, j + iter.second, cur_pos + 1))
                return true;
        }

        board[i][j] = word[cur_pos];

        return false;
    }
};
