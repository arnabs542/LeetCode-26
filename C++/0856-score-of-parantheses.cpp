// Tags: Stack String Amazon
// Time: O(n)
// Space: O(n)
// Similar stack based approach as 0224-basic-calculator
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int res = 0;
        for (char c : S) {
            if (c == '(') {
                // push the previous result and sign just before (
                // and start calculating new result
                st.push(res);
                res = 0;
            } else {
                // either add 1 or make the result double (whichever is higher)
                // also add previous stored result before (
                res += max(res, 1) + st.top();
                st.pop();
            }
        }
        return res;
    }
};

/*
res records the score at the current layer level.

If we meet '(',
we push the current score to stack,
enter the next inner layer level,
and reset res = 0.

If we meet ')',
the res score will be doubled and will be at least 1.
we exit the current layer level,
and set res = stack.pop() + res
*/
