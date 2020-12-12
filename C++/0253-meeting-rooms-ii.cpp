// Tags: Amazon Greedy Sort Premium
// Time:  O(nlogn), using ordered map instead of unordered_map
// Space: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> lookup;
        for (const auto &i: intervals) {
            ++lookup[i[0]];
            --lookup[i[1]];
        }
        int result = 0, cur = 0;
        for (const auto & [time, num]: lookup) {
            result = max(result, cur += num);
        }
        return result;
    }
};

/*
First collect the changes: at what times the number of meetings 
goes up or down and by how much. Then go through those changes 
in ascending order and keep track of the current and maximum 
number of rooms needed. */


// Time:  O(nlogn)
// Space: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (const auto &i: intervals) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int result = 0, cur = 0;
        int i = 0, j = 0;
        while (i < starts.size()) {
            if (starts[i] < ends[j]) {
                // acquire the room
                ++cur;
                result = max(result, cur);
                ++i;
            } else {
                // release the room
                --cur;
                ++j;
            }
        }
        return result;  
    }
};

/* If the current start time comes before the current end time, we
increase the count and i. However, if the current end time comes before
the current start time, we decrease the count but increment j.
Repeat for all start times.
*/
