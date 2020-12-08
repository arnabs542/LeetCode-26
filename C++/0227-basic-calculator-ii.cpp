// Tags: Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int calculate(string s) {
        int result = 0, num = 0;
        char sign = '+';
        vector<int> stack;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num*10 + (c - '0');
            } 
            // if we see a new operator or it is last char, we
            // perform operation using the previous
            // operator and push into stack
            if (!isdigit(c) && !isspace(c) ||  i == s.length() - 1) {
                if (sign == '+') {
                    stack.push_back(num);
                } else if (sign == '-') {
                    stack.push_back(-num);
                } else if (sign == '*') {
                    int num2 = stack.back(); stack.pop_back();
                    stack.push_back(num * num2);
                } else if (sign == '/') {
                    int num2 = stack.back(); stack.pop_back();
                    stack.push_back(num2 / num);
                }
                sign = c;
                num = 0;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};

/*
Unlike basic calculator (0224) here,
we delay addition/subtraction to a later time and only do multiplication/division
while iterating the string, which helps us in implementating DMAS
*/
