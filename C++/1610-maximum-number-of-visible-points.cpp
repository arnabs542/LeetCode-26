// Tags: Geometry Sliding-window Google
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> arr;
        int overlap = 0;
        for (auto p : points) {
            if (p[0] == location[0] && p[1] == location[1])
                ++overlap;
            else
                arr.push_back(atan2(p[1] - location[1], p[0] - location[0]) * 180 / M_PI);
        }
        sort(arr.begin(), arr.end());
        int n = arr.size(), res = 0;
        for (int l = 0, r = 0; r < 2*n; ++r) {
            // or if (...)
            while (360 * (r >= n) + arr[r % n] - 360 * (l >= n) - arr[l % n] > angle)
                ++l;
            res = max(res, r - l + 1);
        }
        return res + overlap;
    }
};
/*
1. Convert all points from cartesian coordinates (x, y) to polar coordinates (r, theta)
   having reference at (posx, posy]) (theta in degrees).
2. Sort the array
3. Use sliding window to find the longest circular window/arc that satisfies
   arr[r] - arr[l] <= angle.

Note that in order for our angle of view to include set of points in both 1st and 4th
quadrant, we need to duplicate the array and offset the second half by 2*pi so that
those points come right after the original points in the sorted array.
*/
