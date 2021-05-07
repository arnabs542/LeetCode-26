// Tags: Ordered-map Google
// Time: O(n^2), where n = number of events booked
// Space: O(n)
// Same as 0253-meeting-rooms-ii
class MyCalendarThree {
    map<int, int> timeline;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++timeline[start];
        --timeline[end];
        int cur = 0, res = 0;
        for (auto [t, cnt] : timeline)
            res = max(res, cur += cnt);
        return res;
    }
};
/*
We can log the start & end of each event on the timeline,
 * each start add a new ongoing event at that time
 * each end terminate an ongoing event.
Then we can scan the timeline to figure out the maximum number of ongoing event at any time.
*/



// Time: O(n^2)
// Space: O(n)
// Faster as we only iterate time points between start and end instead of the whole map.
class MyCalendarThree {
    map<int, int> count;
    int res;
public:
    MyCalendarThree() {
        res = 0;
        // make sure (--count.upper_bound(x)) is never undefined
        // and set the value to 0
        count.emplace(-1, 0);
    }
    
    int book(int start, int end) {
        // if start exists, we get count[start], otherwise
        // we get count[prev] where prev is time point just before start
        int cur = (--count.upper_bound(start))->second;
        // returns <iterator, false> if start key exists and no insertion happens
        // otherwise returns <iterator, true> and insertion happens
        auto s = count.insert({start, cur});
        // do the same for end
        cur = (--count.upper_bound(end))->second;
        auto e = count.insert({end, cur});
        // iterate and increment (update) all the time points in the time window start and end
        // as those are the only values that change after insertion of [start, end)
        for (auto it = s.first; it != e.first; ++it) {
            res = max(res, ++(it->second));
        }
        return res;
    }
};
/*
Instead of storing no of changes at each points, we can store the actual number of active
events (cur in previous approach) at each point.

count[t] means that, from the time point t, we have count[t] active events at the same time,
until the next time point after t.
*/
