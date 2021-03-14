// Tags: Array Sort Amazon
// Time: O(n + i log m), where m is unique elements, and i - number of elements we need to remove.
// Space: O(m) for the hash map and heap.
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnts;
        for (int num : arr)
            ++cnts[num];
        vector<int> p;
        for (auto kvp : cnts)
            p.push_back(kvp.second);
        priority_queue<int, vector<int>, greater<int>> min_heap(p.begin(), p.end());
        while (k > 0) {
            // last iter
            if (min_heap.top() > k)
                break;
            k -= min_heap.top(); min_heap.pop();
        }
        return min_heap.size();
    }
};
