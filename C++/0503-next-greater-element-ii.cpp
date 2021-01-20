// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
// Monotonic decreasing stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        // we store indices of nums in stack
        // as result needs to be put at the same indices
        // in res array
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

/*
The typical way to solve circular array problems is to
extend the original array to twice length, 2nd half has the 
same element as first half. Then everything become simple.
*/
