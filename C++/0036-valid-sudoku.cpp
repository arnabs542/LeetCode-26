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
                    // r\c 0 1 2
                    //   0 0 1 2
                    //   1 3 4 5   i/3 tells either 0, 1 or 2th row of blocks
                    //   2 6 7 8   j/3 tells either 0, 1 or 2th col of blocks
                    // now, think of all blocks arranged in one line i.e. 0 1 2 3 4 5 6 7 8
                    // as we know row and col, we can encode as follows: x*3 + y
                    int k = (i/3)*3 + j/3;
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



// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    string number {board[i][j]};
                    if (seen.count(number + " in row " + to_string(i)) || 
                        seen.count(number + " in column " + to_string(j)) || 
                        seen.count(number + " in block " + to_string(i/3) +
                            "-" + to_string(j/3)))
                        return false;
                    seen.insert(number + " in row " + to_string(i));
                    seen.insert(number + " in column " + to_string(j));
                    // block in i/3th row and j/3th col
                    seen.insert(number + " in block " + to_string(i/3) + 
                        "-" + to_string(j/3));
                }
            }
        }
        return true;
    }
};
/*
We can make encoded strings more clear and self-explaining.
*/



// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    string b = "(";
                    b += board[i][j];
                    b += ")";
                    if (seen.count(b + to_string(i)) ||
                        seen.count(to_string(j) + b) ||
                        seen.count(to_string(i/3) + b + to_string(j/3)))
                        return false;
                    seen.insert(b + to_string(i));
                    seen.insert(to_string(j) + b);
                    seen.insert(to_string(i/3) + b + to_string(j/3));
                }
            }
        }
        return true;
    }
};

/*
Collect the set of things we see, encoded as strings. For example:

    '4' in row 7 is encoded as "(4)7".
    '4' in column 7 is encoded as "7(4)".
    '4' in the top-right block is encoded as "0(4)2".

Scream false if we ever fail to add something because it was already added (i.e., seen before).
*/
