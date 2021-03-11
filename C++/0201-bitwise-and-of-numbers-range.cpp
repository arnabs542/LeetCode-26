// Tags: Bit-manipulation Amazon
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};

/*
One might notice that after the AND operation on all the numbers, 
the remaining part of bit strings is the common prefix of all these bit strings.

As a result, we then can reformulate the problem as
"given two integer numbers, we are asked to find the common prefix of their binary strings."

Algo:
1. We reduce both numbers into their common prefix, by doing right shift iteratively.
   During the iteration, we keep the count on the number of shift operations we perform.

2. With the common prefix, we restore it to its previous position, by left shifting.
*/
