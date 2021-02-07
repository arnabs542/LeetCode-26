// Tags: Stack Math Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        int result = 0, num = 0, sign = 1;
        for (const auto c: s) {
            if (c == '(') {
                // push the previous result and sign just before (
                // and start calculating new result
                stack.push_back(result);
                stack.push_back(sign);
                // reset the sign, num and result for the value in the parenthesis
                result = 0;
                num = 0;
                sign = 1;
            } else if (c == '+') {
                result += num*sign;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += num*sign;
                num = 0;
                sign = -1;
            } else if (c == ')') {
                result += num*sign;
                // update the result with sign just before (
                result *= stack.back(); stack.pop_back();
                // add result to previous stored result before (;
                result += stack.back(); stack.pop_back();
                num = 0;
            } else if (isdigit(c)) {
                num = 10*num + (c - '0');
            }
        }
        if (num)
            result += num*sign;
        return result;
    }
};
