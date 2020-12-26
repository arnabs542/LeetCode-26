// Time: O(n)
// Space: O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string ch: tokens) {
            if (ch == "+") {
                int a = st.top(); st.pop();
                st.top() += a;
            } else if (ch == "-") {
                int a = st.top(); st.pop();
                st.top() -= a;
            } else if (ch == "/") {
                int a = st.top(); st.pop();
                st.top() /= a;
            } else if (ch == "*") {
                int a = st.top(); st.pop();
                st.top() *= a;
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};



// Time: O(n)
// Space: O(n)
// Fancy lambda expression solution
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};
