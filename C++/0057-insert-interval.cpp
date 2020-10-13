// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t i = 0;
        // Insert intervals appeared before newInterval.
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        res.push_back(newInterval);

        // Insert intervals appearing after newInterval.
        copy(intervals.begin() + i, intervals.end(), back_inserter(res));
        return res;
    }
};
