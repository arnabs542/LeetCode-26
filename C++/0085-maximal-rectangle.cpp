// Tags: DP Top-100-liked Stack
// Time: O(m*n)
// Space: O(m*n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            
            for (int j = 0; j < n; ++j)
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else {
                    cur_left = j + 1;
                    left[j] = 0; // reset for the next row
                }
            
            for (int j = n - 1; j >= 0; --j)
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    cur_right = j; // should have been j - 1
                    right[j] = n; // reset for the next row
                }
            
            // when matrix[i][j] == 0, we don't care about left[j] & right[j]
            // as area will automatically be 0 when * by height[j]
            for (int j = 0; j < n; ++j)
                res = max(res, (right[j] - left[j])*height[j]);
        }
        return res;
    }
};

/*
Finding the maximum height of the rectangle by iterating upwards 
until a 0 is reached.

Finding the maximum width of the rectangle by iterating outwards
left and right until a height that doesn't accommodate the maximum
height of the rectangle.

For each point h = height, l = left bound, r = right bound

We can use the h, l, and r of each point in the previous row 
to compute the h, l, and r for every point in the next row in 
linear time.

h[i] = number of continuous ones (above) in a line from our point.

cur_left = one greater than rightmost occurence of zero we have
           encountered

cur_right = the leftmost occurrence of zero we have encountered
            (for sake of simplicity, we don't decrement cur_right 
            by one, like how we increment cur_left)

=> the base of the rectangle is defined as [l r)

*/



// Time: O(n*m)
// Space: O(n)
// Reusing 0084-largest-rectangle-in-histogram
// Monotone increasing stack
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                h[j] = (matrix[i][j] == '1') ? h[j] + 1 : 0;
            stack<int> st;
            int area = 0, j = 0;
            while (j < n) {
                if (st.empty() || h[j] >= h[st.top()])
                    st.push(j++);
                else {
                    int top = st.top(); st.pop();
                    if (st.empty())
                        area = h[top]*j;
                    else
                        area = h[top]*(j - st.top() - 1);
                    res = max(res, area);
                }
            }

            while (!st.empty()) {
                int top = st.top(); st.pop();
                if (st.empty())
                    area = h[top]*j;
                else
                    area = h[top]*(j - st.top() - 1);
                res = max(res, area);
            }
        }
        return res;
    }
};
