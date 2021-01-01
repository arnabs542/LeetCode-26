// Tags: Hash-table Math Top-interview
// Time: O(n^2)
// Space: O(n^2), in worst case, all pair of points
// can have different slopes
class Solution {
    // evaluate greatest common divisor using Euclid’s algorithm
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> counter;

            // duplicate points, initialize to 1 as we need to add
            // one to counter for the origin point i.e. points[i]
            int dup = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    ++dup;
                else {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int g = gcd(dx, dy);
                    ++counter[to_string(dx/g) + '_' + to_string(dy/g)]; 
                }
            }
            res = max(res, dup);
            for (auto p: counter)
                res = max(res, p.second + dup);
        }
        return res;
    }
};

/*
Brute force:
Traverse all possible pairs of points and see how many other points
fall in the line determined by them, which gives an O(n^3) solution.

To improve time complexity:
Given a point p, we compute the slopes of all lines connecting p and
other points. Points corresponding to the same slope will fall on
the same line. In this way, we can figure out the maximum number of
points on lines containing p.

We exhaust all possible ps and the largest maximum number is just 
the answer.
*/
