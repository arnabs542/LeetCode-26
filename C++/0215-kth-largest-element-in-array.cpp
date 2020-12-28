// Tags: Heap
// Time: O(n) ~ O(n^2)
// Space: O(1)
// Quick select solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // auto it = nums.end() - k;
        // nth_element(nums.begin(), it, nums.end());
        // return *it;
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};



// Time: O(nlogk)
// Space: O(k)
// Min-heap solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto n: nums) {
            min_heap.push(n);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        return min_heap.top();
    }
};
