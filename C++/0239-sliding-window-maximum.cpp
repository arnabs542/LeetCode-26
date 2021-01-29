// Tags: Sliding-window Deque Amazon
// Time: O(n) (amortized), as each element is pushed and popped only once
// Space: O(n)
// Monotonic decreasing deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (size_t i = 0; i < nums.size(); ++i) {
            // out of range [i - (k - 1), i]
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};


/*
Intuition:
As we are moving sliding window, popping one elem from front and pushing one to
end at each iteration, we need a queue. Also at each iteration, we need to find
max_element in the queue. ...... Repeat the same for i - k + 1 iterations.

Why deque?:
We can improve it by only keeping track of promising elements,
which are potentially maximum number in window [i - (k - 1), i]. So we need
to pop from back as well and therefore require deque. This way the maximum
element will always be the head and we can obtain it in O(1).

Algo:
1. If an element is out of i - (k - 1), we discard it
2. We discard elements smaller than a[i] from the tail. This is because
if a[x] < a[i] and x < i, then a[x] has no chance to be the "max" in [i-(k-1),i],
or any other subsequent window: a[i] would always be a better candidate.
3. As a result the resulting elements are ordered both in sequence and their value
   (monotonic decreasing in values). Also, at each step the head of the deque is the
   max element in [i-(k-1),i]
*/
