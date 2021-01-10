// Tags: BFS Amazon
// Time: O(n^2), we only visit each cell once
// Space: O(n^2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_set<int> visited{1};
        queue<int> q; q.push(1);
        int moves = 0;
        int n = board.size();
        while (!q.empty()) {
            int sz = q.size();
            ++moves;
            while (sz-- > 0) {
                int cur = q.front(); q.pop();
                for (int i = cur + 1; i <= cur + 6; ++i) {
                    // coordinates if origin is considered at bottom left
                    // -1 to make it 0-indexed
                    int next = i;
                    int r = (next - 1)/n, c = (next - 1) % n;
                    // coordinates if origin is considered at top left
                    // 0th row (even) is always iterated from left to right
                    c = (r % 2 == 0) ? c : n - 1 - c;
                    r = n - 1 - r;
                    if (board[r][c] > 0)
                        next = board[r][c];
                    if (next == n*n)
                        return moves;
                    // prevent from going back if snake is encounted
                    // we simply skip that move
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};

/*
Each cell has either snake, ladder or -1. It can't have both ladder
and snake unlike real board game.
Further starting cell will always be negative (no ladder).
*/
