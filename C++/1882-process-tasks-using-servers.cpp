// Tags: Heap WC243
// Time: O(m*log(n)), m = number of tasks, n = number of servers
// Space: O(n)
// Quite similar to 1834-single-threaded-cpu
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // weight, idx
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> avl;
        // free time, idx
        priority_queue<T, vector<T>, greater<T>> unavl;
        for (int i = 0; i < servers.size(); ++i)
            avl.push({servers[i], i});
        int time = 0;
        vector<int> res(tasks.size());
        // Apart from being the index of next task to process, i is also the time
        // ith task becomes available to be processed
        for (int i = 0; i < tasks.size(); ++i) {
            while (!unavl.empty() && unavl.top().first <= time) {
                avl.push({servers[unavl.top().second], unavl.top().second});
                unavl.pop();
            }
            auto [weight, idx] = avl.top(); avl.pop();
            res[i] = idx;
            unavl.push({time + tasks[i], idx});
            if (!avl.empty()) {
                /*
                 * Suppose previously there was a case where no servers were available and
                 * therefore we advanced the time to the free time of the first unavailable
                 * server, say free time was 6
                 * Now, the next task became available at time i = 3. We won't increment time
                 * to 7, infact time remains the same, as we can process multiple tasks
                 * at the same time as long as there are servers available.
                 */
                time = max(time, i + 1);
                // not ++time or time = i + 1
            } else {
                time = unavl.top().first;
            }
        }
        return res;
    }
};
