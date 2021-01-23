// Tags: Array Stack Top-100-liked Top-interview Amazon
// Time: O(n), 2*n (each number can be pushed & popped only once)
// Space: O(n)
// Monotone increasing stack
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
                
                // if stack is not empty then everything from i-1 to stack.peek() + 1
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

(increasing stack and L to R -> next smaller element)

Calculate area everytime you remove
    if(stack is empty)
        area = input[top]*i
    else
        area = input[top]*(i - stack.top - 1)

*/



// Similar structure to Finding Next Smaller Element
// (Easier to remember)
// Monotonic increasing stack, iterating left to right
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        size_t i;
        int area = 0, res = 0;
        for (i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                // calculate area of block with height = heights[idx]
                // (continuing on both sides)
                int idx = st.top(); st.pop();
                if (st.empty()) {
                    // lesser height not present on left side
                    // area from index (-1 + 1) to i
                    area = heights[idx]*(i - (-1) - 1);
                } else {
                    // lesser height present on left side
                    // area from index (st.top() + 1) to i
                    area = heights[idx]*(i - st.top() - 1);
                }
                res = max(res, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int idx = st.top(); st.pop();
            if (st.empty())
                area = heights[idx]*i;
            else
                area = heights[idx]*(i - st.top() - 1);
            res = max(res, area);
        }
        return res;
    }
};
/*
Intuition behind using Monotonic stack: 
for every bar, we need a know the indices of bars with lesser
heights on both sides.
*/
