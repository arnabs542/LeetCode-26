// Tags: Amazon Design Premium
// Time: O(1)
// Space: O(n)
class TicTacToe {
    // count parameter: player 1 + : player 2: -
    vector<int> rowJudge;
    vector<int> colJudge;
    int diag, anti;
    // total moves required to win
    int total;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rowJudge(n), colJudge(n), diag(0), anti(0), total(n) {
        
    }
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rowJudge[row] += add;
        colJudge[col] += add;
        diag += row == col ? add : 0;
        anti += row == total - 1 - col ? add : 0;
        if (abs(diag) == total || abs(anti) == total || abs(rowJudge[row]) == total
            || abs(colJudge[col]) == total)
            return player;
        return 0;
    }
};
