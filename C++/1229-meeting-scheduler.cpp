// Tags: Two-pointers Sort Heap Amazon Premium
// Time: O(nlogn)
// Space: O(1)
// Two pointers solution
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            // finding boundaries of overlapping intervals
            int left = max(slots1[i][0], slots2[j][0]);
            int right = min(slots1[i][1], slots2[j][1]);
            if (left + duration <= right)
                return {left, left + duration};
            if (slots1[i][1] < slots2[j][1])
                ++i;
            else
                ++j; // slots2[j][1] <= slots1[i][1]
        }
        return {};
    }
};



// Time: O(nlogn)
// Space: O(n)
// Priority queue solution
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        // This helps avoid cases when 'right' is taken from the second interval
        // e.g. [0,          120]
        //          [10, 50]
        // interval = 50
        // we are making sure that 'right' will always be taken from the first interval
        // and 'left' being taken from the second interval is made sure by our sorting logic
        // greater<pair<int, int>>
        for (auto s : slots1) {
            if (s[1] - s[0] >= duration)
                min_heap.push({s[0], s[1]});
        }
        for (auto s : slots2) {
            if (s[1] - s[0] >= duration)
                min_heap.push({s[0], s[1]});
        }
        // atleast two intervals present
        // (at each iteration, we are taking 'left' from second interval
        // and 'right' from the first interval)
        while (min_heap.size() > 1) {
            // finding boundaries of overlapping intervals
            int right = min_heap.top().second;
            min_heap.pop();
            // don't pop the second interval yet
            int left = min_heap.top().first;
            if (left + duration <= right)
                return {left, left + duration};
        }
        return {};
    }
};
/*
Since it is guaranteed that no two availability slots of the same person
intersect with each other, we can use a priority queue.
*/
