// Tags: WC237 Heap
// Time: O(nlogn), each task is only pushed and popped once
// Space: O(n)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res, indices(tasks.size());
        iota(indices.begin(), indices.end(), 0);
        priority_queue<pair<int, int>> min_heap;
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });
        // current time, index to indices array
        long time = 1; size_t i = 0;
        while (i < indices.size() || !min_heap.empty()) {
            for (; i < indices.size() && tasks[indices[i]][0] <= time; ++i)
                min_heap.push({-tasks[indices[i]][1], -indices[i]});
            if (!min_heap.empty()) {
                auto [proc, idx] = min_heap.top(); min_heap.pop();
                res.push_back(-idx);
                proc = -proc;
                time += proc;
            } else {
                // if available tasks = {} ie empty,
                // advance time to the next unqueued task's enqueue time
                time = tasks[indices[i]][0];
            }
        }
        return res;
    }
};
/*
Here, we just need to do exactly what we were told to do.
1. Since tasks can be in any order, we need to sort them first by the enqueue time
2. We track the current time. First, we get all available tasks with the enqueue time less
   or equal than time and queue them using a min heap prioritized by both duration and index.
3. Then we pop the next task from our heap and "execute" it.
   If no scheduled tasks are available, we advance the current time to the smallest enqueue
   time of all unqueued tasks.
*/
