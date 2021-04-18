// Tags: Sliding-window Deque Google
// Time: O(n), we process each element atmost twice
// Space: O(n)
// Monotonic decreasing deque
// Similar to 0239-sliding-window-maximum
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int res = INT_MIN;
        for (size_t j = 0; j < points.size(); ++j) {
            while (!dq.empty() && points[dq.front()][0] < points[j][0] - k)
                dq.pop_front();

            if (!dq.empty())
                res = max(res, points[dq.front()][1] - points[dq.front()][0] +
                    points[j][1] + points[j][0]);

            while (!dq.empty() && points[dq.back()][1] - points[dq.back()][0] <
                points[j][1] - points[j][0])
                    dq.pop_back();
            dq.push_back(j);
        }
        return res;
    }
};
/*
We want to maximize yi + yj + |xi - xj|
    => yi + yj + xj - xi
    => (yi - xi) + yj + xj
So lets just keep track of promising (yi - xi) within reach (xj - xi <= k).
This gives us a monotonic decreasing deque and the maximum (yi - xi) will always be at the front.
*/
