// Tags: DFS Amazon Premium
// Time: O(m*n)
// Space: O(m*n)
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    // Up, Right, Down, Left
    vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void clean(Robot& robot, int x, int y, int curDirNum, unordered_set<string> &visited) {
        // clean current cell
        robot.clean();
        visited.insert(to_string(x) + " " + to_string(y));
        // move in all directions starting from the one robot is currently
        // facing
        for (int dirNum = curDirNum ; dirNum < curDirNum + 4; ++dirNum) {
            int idx = dirNum % 4;
            int nx = x + directions[idx].first;
            int ny = y + directions[idx].second;
            if (!visited.count(to_string(nx) + " " + to_string(ny)) && robot.move())
                clean(robot, nx, ny, dirNum, visited);
            // change orientation
            robot.turnRight();
        }
        // move backward one step while maintaining the orientation.
        // turn 180 degrees to opposite direction
        robot.turnRight();
        robot.turnRight();
        robot.move();
        // turn 180 degrees back to get to same direction
        robot.turnRight();
        robot.turnRight();
    }

public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        clean(robot, 0, 0, 0, visited);
    }
    
};
