// Tags: Math Amazon
// Time: O(n)
// Space: O(1)
// Somewhat similar to 0489-robot-room-cleaner 
class Solution {
public:
    bool isRobotBounded(string instructions) {
        // location of robot
        int x = 0, y = 0;
        // direction he is facing, 0 -> U, 1 -> R, 2 -> D, 3 -> L
        int i = 0;
        vector<vector<int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (char &ins : instructions) {
            if (ins == 'R') {
                i = (i + 1) % 4;
                // i + 1 is dirNum
            } else if (ins == 'L') {
                i = (i + 3) % 4;
                // i + 3 is dirNum
            } else {
                // move in direction being faced
                x += d[i][0];
                y += d[i][1];
            }
        }
        return x == 0 && y == 0 || i > 0;
    }
};
/*
1. If robot returns to origin, there is obviously a circle.
2. If robot finishes with face not towards north, it will get
back to initial status in another one or two sequences.
*/
