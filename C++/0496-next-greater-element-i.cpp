// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
// Monotonic decreasing stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        for (int n: nums2) {
            while (!st.empty() && n > st.top()) {
                m[st.top()] = n; 
                st.pop();
            }
            st.push(n);
        }
        vector<int> res;
        for (int n: nums1)
            res.push_back(m.count(n) ? m[n] : - 1);
        return res;
    }
};

/* 
   Greater -> Decreasing Stack
   Next -> Iterate from left to right
*/
