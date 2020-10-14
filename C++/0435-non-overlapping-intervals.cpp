// Time:  O(nlogn)
// Space: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [] (vector<int> &l, vector<int> &r) {return l[0] < r[0];});
        int res = 0;
        vector<int> prev {intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev[1]) {
                if (intervals[i][1] < prev[1]) {
                    // take the smaller range so that we remove less intervals
                    prev = intervals[i];
                }
                ++res;
            } else {
                prev = intervals[i];
            }
        }
        return res;
    }
};
