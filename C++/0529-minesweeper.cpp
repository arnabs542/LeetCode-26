// Tags: DFS BFS Amazon
// Time:  O(m * n)
// Space: O(m * n)
// Bfs solution
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        queue<vector<int>> q;
        q.push(click);
        while (!q.empty()) {
            int r = q.front()[0], c = q.front()[1]; 
            q.pop();
            if (board[r][c] == 'M') {
                board[r][c] = 'X';
            } else {
                int surCnt = 0;
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        if (i == 0 && j == 0)
                            continue;
                        int nr = r + i, nc = c + j;
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                            continue;
                        if (board[nr][nc] == 'M')
                            ++surCnt;
                    }
                }
            
                if (surCnt > 0) {
                    board[r][c] = surCnt + '0';
                } else {
                    board[r][c] = 'B';
                    for (int i = -1; i < 2; ++i) {
                        for (int j = -1; j < 2; ++j) {
                            if (i == 0 && j == 0)
                                continue;
                            int nr = r + i, nc = c + j;
                            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                                continue;
                            vector<int> next_click = {nr, nc};
                            if (board[nr][nc] == 'E') {
                                q.push(next_click);
                                // Optimization: Avoid this cell to be added again by any of
                                // the 8 adjacent cells being added currently
                                // (this is not required in Dfs as it goes into the depth 
                                // and visit this cell first)
                                board[nr][nc] = 'C';
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};



// Dfs solution
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        } else {
            int surCnt = 0;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    if (i == 0 && j == 0)
                        continue;
                    int nr = r + i, nc = c + j;
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if (board[nr][nc] == 'M')
                        ++surCnt;
                }
            }
            
            if (surCnt > 0) {
                board[r][c] = surCnt + '0';
            } else {
                board[r][c] = 'B'; // visited
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        if (i == 0 && j == 0)
                            continue;
                        int nr = r + i, nc = c + j;
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                            continue;
                        vector<int> next_click = {nr, nc};
                        if (board[nr][nc] == 'E') // go to un-visited cells
                            updateBoard(board, next_click);
                    }
                }
            }
        }
        return board;
    }
};
/*
1. If click on a mine ('M'), mark it as 'X', stop further search.
2. If click on an empty cell ('E'), depends on how many surrounding mine:
    2.1 Has surrounding mine(s), mark it with number of surrounding mine(s),
        stop further search.
    2.2 No surrounding mine, mark it as 'B', continue search its 8 neighbors.
*/
