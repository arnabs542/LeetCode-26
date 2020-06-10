// Time: O(nlogk)
// Space: O(n)
// Heap Solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> counts;
        for (const auto &n: nums)
            ++counts[n];
        // default max heap in c++
        priority_queue<pair<int,int>> heap;
        // we need min heap
        for (const auto &c: counts) {
            heap.emplace(-c.second, c.first);
            // .push(make_pair(-c.second, c.first));
            // if heap becomes full remove the
            // lowest freq elem
            if (heap.size() == k + 1)
                heap.pop();
        }

        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().second);
            // or .emplace_back
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
