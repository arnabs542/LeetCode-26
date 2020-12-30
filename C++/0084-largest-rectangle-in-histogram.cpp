// Tags: Array Stack Top-100-liked Top-interview
// Time: O(n), 2*n (each number can be pushed & popped only once)
// Space: O(n)
// Using Stack, monotone increasing sequence
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stores indices
        stack<int> st;
        size_t i = 0;
        int area = 0, maxArea = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[i] >= heights[st.top()])
                st.push(i++);
            else {
                int top = st.top(); st.pop();
                // if stack is empty means everything till i has to be
                // greater or equal to input[top] so get area by
                // input[top] * i;
                if (st.empty())
                    area = heights[top]*i;
                
                // if stack is not empty then everything from i-1 to input.top() + 1
                // has to be greater or equal to input[top]
                // so area = input[top]*(i - stack.peek() - 1);
                else
                    area = heights[top]*(i - st.top() - 1);
                maxArea = max(area, maxArea);
            }
        }
        while (!st.empty()) {
            int top = st.top(); st.pop();
            if (st.empty())
                area = heights[top]*i;
            else
                area = heights[top]*(i - st.top() - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

/*
Add to stack if current value is equal or greater than top of the
stack.

Otherwise keep removing from stack until a number which is smaller
or equal than current is found.

Calculate area everytime you remove
    if(stack is empty)
        area = input[top]*i
    else
        area = input[top]*(i - stack.top - 1)

*/
