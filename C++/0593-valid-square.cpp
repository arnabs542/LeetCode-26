// Tags: Math Google
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto d = [](vector<int> x, vector<int> y) {
            return (x[0] - y[0])*(x[0] - y[0]) + (x[1] - y[1])*(x[1] - y[1]);
        };
        // all 6 combinations
        unordered_set<int> s{d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)};
        // none of the line segments are of length 0 and two different lengths present
        return !s.count(0) && s.size() == 2;
    }
};
/*
If the 4 edges are equal to each other, that means it should be equilateral paralellogram.
Finally, if the 2 diagonals are also equal to each other, then it is a square.
*/
