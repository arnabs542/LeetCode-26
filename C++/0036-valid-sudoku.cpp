// Tags: Hash-table Top-interview-questions
// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] {0}, used2[9][9] {0}, used3[9][9] {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    // -1 to make it 0-indexed
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;
                    if (used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        }
        return true;
    }
};

/*
Three flags are used to check whether a number appear.

used1: check each row

used2: check each column

used3: check each sub-boxes
*/