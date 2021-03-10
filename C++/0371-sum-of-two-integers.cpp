// Time:  O(1)
// Space: O(1)
// Approach 1: Language-independent
class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a), y = abs(b);
        if (x < y) // This doesn't matter in case 1 ie sum
            return getSum(b, a);
        // a being integer with higher magnitude
        int sign = a > 0 ? 1 : -1;
        if (a*b >= 0) {
            // sum of two positive integers, when x > y
            // while carry is not equal to zero
            while (y) {
                // answer without carry
                int answer = x ^ y;
                // need to add carry to answer
                int carry = (x & y) << 1;
                // answer becomes new x
                x = answer;
                // carry becomes new y
                y = carry;
            }
        } else {
            // difference of two positive integers, when x > y
            // while borrow if not equal to zero
            while (y != 0) {
                // answer without borrow
                int answer = x ^ y;
                // need to subtract borrow from answer
                int borrow = (~x & y) << 1;
                // answer becomes new x
                x = answer;
                // borrow becomes new y
                y = borrow;
            }
        }
        return x * sign;
    }
};
/*
There are too many cases:
both a and b could be +ve or -ve, abs(a) could be greater or less than abs(a).
In total 2 x 2 x 2 = 8 use cases.

Let's reduce to two cases
* Sum of two +ve integers: x + y, where x > y
* Difference of two +ve integers: x - y, where x > y
*/



// Approach 2: Language specific
// (considering negative number is represented in two's complement)
class Solution {
public:
    int getSum(int a, int b) {
        // where carry is not equal to zero
        while (b != 0) {
            int answer = a ^ b;
            // unsigned int because when carry = 100000..31 zeros, it becomes
            // a negative number and thus can't be left shifted anymore
            int carry = (unsigned int)(a & b) << 1;
            a = answer;
            b = carry;
        }
        return a;
    }
};
