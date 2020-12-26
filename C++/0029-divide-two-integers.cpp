// Tags: Math Binary-search
// Time: O(logn^2)
// Space: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // since abs(INT_MIN) > INT_MAX
        // and ques asks to return 2^31 − 1 when 
        // the division result overflows.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // labs: long absolute
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            // left shift temp until it remains <= dvd
            // m (current quotient) is either 1 or multiples of 2
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            // update dvd
            dvd -= temp;
            // update total quotient
            ans += m;
        }
        return sign * ans;
    }
};

/* Time complexity:
let dividend be D, divisor be S, n be the number of times we shift left. Because we know
S * [2^(n + 1)] > D (that's why we have to end the inner loop)
=> S * (2^n) * 2 > D
=> S * (2^n) > D/2
=> S * (2^n) > D - D/2
=> D - S * (2^n) < D/2
Now we know D - S * (2^n) < D/2.
D - S * (2^n) is the value we have after the inner loops end. It is less than D/2, 
which means everytime D decreases at least by half. 
Therefore the outer loop will execute at most logN time.
It is trivial to see inner loop execute logN time. Therefore the time complexity is O((logN)^2).
*/

/*
The key observation is that the quotient of a division is just the number of times
that we can subtract the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by
shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12.
Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most
subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice, it is
1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0).
The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), 
with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining
dividend = 3 and obtain 0

To do: solution only without long (kamyu)
*/



// Doesnt' work
// overflow when a = INT_MIN
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int a = abs(dividend), b = abs(divisor), res = 0, x = 0;
        while (a - b >= 0) {
            // overflow here (can't left shift negative integer)
            for (x = 0; a - (b << x) >= 0; ++x);
            x -= 1;
            res += 1 << x;
            a -= b << x;
        }
        return (dividend > 0) == (divisor > 0) ? res: -res;
    }
}
