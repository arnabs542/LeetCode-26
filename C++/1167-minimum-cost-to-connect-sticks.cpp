// Tags: Amazon Premium Greedy
// Time: O(nlogn)
// Space: O(n)
// Similar to how huffman tree is built
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // create heap using heapify
        priority_queue<int, vector<int>, greater<int>> min_heap(sticks.begin(), sticks.end());
        int res = 0;
        while (min_heap.size() > 1) {
            // pop two smallest sticks
            int s1 = min_heap.top(); min_heap.pop();
            int s2 = min_heap.top(); min_heap.pop();
            // combine them & add to cost
            res += s1 + s2;
            // the combined stick may not be the smallest in min_heap
            min_heap.push(s1 + s2);
        }
        return res;
    }
};

/* Greed: Always pick two of the smallest sticks to connect
   and continue doing this until you get only one stick.
*/
