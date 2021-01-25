// Tags: Array Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // 'right' is the number of the rightmost lighted bulb.
        int right = -1, res = 0;
        for (auto i = 0; i < light.size(); ++i) {
            int totalBulbs = i + 1;
            right = max(right, light[i]);
            if (right == totalBulbs) {
                // if 'right' is i + 1th bulb, all bulbs from 1....i
                // must be turned on too
                 ++res;
            }
        }
        return res;
    }
};

/*
Index i tells us the total number of bulbs that have been
turned on -> i + 1.
So, if 'right' matches total number of bulbs seen so far,
it means all the bulbs from 1....i+1 are turned on
(and therefore blue).
*/
