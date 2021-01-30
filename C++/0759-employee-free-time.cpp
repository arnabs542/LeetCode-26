// Tags: Line-sweep Heap Amazon Premium Greedy
// Time: O(clogc), c is the number of intervals across
// all employees
// Space: O(c)
// Events (line sweep) approach
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int OPEN = 0, CLOSE = 1;
        vector<pair<int, int>> events;
        for (vector<Interval> employee : schedule) {
            for (Interval inv : employee) {
                events.emplace_back(inv.start, OPEN);
                events.emplace_back(inv.end, CLOSE);
            }
        }
        sort(events.begin(), events.end());
        vector<Interval> res;
        // prev event coordinate
        int prev = -1, bal = 0;
        for (auto event: events) {
            if (prev != -1 && bal == 0) {
                // event[0] denotes the very first interval after
                // bal = 0 is observed
                res.push_back(Interval(prev, event.first));
            }
            // same as what we do to find matching brackets
            bal += event.second == OPEN ? 1 : -1;
            prev = event.first;
        }
        return res;
    }
};
/*
we could reduce our problem to the following:
given a set of intervals, find all places where there are no intervals.

For each interval [s, e], we can think of this as two events:
balance++ when time = s, and balance-- when time = e. 
We want to know the regions where balance == 0
*/



// Time: O(clogn), n is the number of employee, c is the number of intervals
// across all employees
// Space: O(n)
// Heap solution, similar idea as 0023-merge-k-sorted-lists
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        // start time, employee id, interval id for this employee
        using T = tuple<int, int, int>;
        // sorted by start time
        priority_queue<T, vector<T>, greater<T>> min_heap;
        for (auto i = 0; i < schedule.size(); ++i) {
            // put first intervals of each employee
            min_heap.emplace(schedule[i][0].start, i, 0);
        }
        int last_end = -1;
        while (!min_heap.empty()) {
            auto [start, emp, inv] = min_heap.top(); min_heap.pop();

            // check if there is a free time
            if (last_end != -1 && last_end < start)
                res.push_back(Interval(last_end, start));

            // last end is the max among all overlapping intervals
            last_end = max(last_end, schedule[emp][inv].end);

            // if this employee has more remaining intervals
            if (inv + 1 < schedule[emp].size())
                min_heap.emplace(schedule[emp][inv + 1].start, emp, inv + 1);
        }
        return res;
    }
};
/*
We know interval list for each employee is already sorted.
So let's maintain a heap of the next time an employee has to work,
and it's associated job.

Say we are at some time when no employee is working. That work-free
period will last until the next time some employee has to work.

When we process the next time from the heap, we can add the next job
for that employee.
*/
