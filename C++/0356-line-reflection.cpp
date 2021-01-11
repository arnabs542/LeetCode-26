// Tags: Amazon Hash-table Math Premium
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int minX = INT_MAX, maxX = INT_MIN;
        unordered_set<string> pointSet;
        for (const auto &p: points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pointSet.insert(to_string(p[0]) + "-" + to_string(p[1]));
        }
        int sum = minX + maxX;
        for (const auto &p: points) {
            if (!pointSet.count(to_string(sum - p[0]) + "-" + to_string(p[1])))
                return false;
        }
        return true;
    }
};



// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int left = numeric_limits<int>::max();
        int right = numeric_limits<int>::min();
        unordered_map<int, unordered_set<int>> y2x;
        for (const auto &p: points) {
            left = min(left, p[0]);
            right = max(right, p[0]);
            y2x[p[1]].insert(p[0]);
        }
        int sum = left + right;
        for (const auto &kvp: y2x) {
            for (const auto &x: kvp.second) {
                if (!kvp.second.count(sum - x))
                    return false;
            }
        }
        return true;
    }
};

/*
If there exists a line reflecting the points, then each pair of symmetric
points will have their x coordinates adding up to the same value, including
the pair with the maximum and minimum x coordinates. 

So, in the first pass, I iterate through the array, adding each point to the 
hash set, and keeping record of the minimum and maximum x coordinates. 

Then, in the second pass, I check for every point to the left of the reflecting
line, if its symmetric point is in the point set or not. If all points pass the
test, then there exists a reflecting line. Otherwise, not.

Note: the line will always be at the middle of the leftmost and rightmost point.
*/
