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
            // .push({-c.second, c.first});
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

/*
Min-heap:
              *        kth largest element
            /   \
           *     *
          / \   / \
         *   * *   *   largest element
*/



// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(n)
// Quick Select Solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n: nums)
            ++count[n];
        vector<pair<int, int>> p;

        // negative to change out of nth_element from
        // kth smallest to kth largest
        for (auto &kvp: count)
            p.push_back({-kvp.second, kvp.first});

        // kth position is placed at its sorted position
        // therefore all elements before it are smaller (more negative)
        // and all elements after it are greater (less negative)
        // (no matter what their internal order is)
        nth_element(p.begin(), p.begin() + k - 1, p.end());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(p[i].second);
        }
        return res;
    }
};



// Time:  O(n)
// Space: O(n)
// Bucket Sort Solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n: nums)
            ++count[n];
        // if all elements are same, largest freq = nums.size()
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto &kvp: count)
            buckets[kvp.second].push_back(kvp.first);

        vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                res.push_back(buckets[i][j]);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
