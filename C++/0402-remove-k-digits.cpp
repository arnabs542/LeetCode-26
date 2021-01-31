// Tags: Greedy Stack Amazon
// Time:  O(n)
// Space: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        // behaving as stack
        string st;
        for (char c : num) {
            // If digit is greater than next one, delete it.
            while (k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                --k;
            }
            st.push_back(c);
        }
        // If all digits are increasingly sorted, delete last k
        // otherwise k = 0
        st.resize(st.length() - k);

        // strip all leading '0
        auto pos = st.find_first_not_of("0");
        return st.empty() || pos == string::npos ? "0" : st.substr(pos);
    }
};
/*
Intuition:
we should iterate from the left to right, when removing the digits.
The more a digit to the left-hand side, the more weight it carries.

Algo:
Given a sequence of digits [d1 d2 d3 ... dn], if digit d2
is less than its left neighbor d1, then we should remove left
neighbor d1 in order to obtain the minimum result.

By removing the digits one by one, we are steadily approaching the
optimal solution step by step -> greedy paradigm.

In other words, we want to maintain an monotonic increasing
sequence.
*/
