// Tags: Recursion Google Premium
// Time: O(4 * log(N)), where log10(N) = number of digits in N
// Space: O(log(N))
class Solution {
public:
    int confusingNumberII(int N) {
        vector<int> valid {0, 1, 6, 8, 9};
        unordered_map<int, int> mapping {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        int cnt = 0;
        // generates all possible numbers smaller than N leading with num
        function<void(long, long, int)> helper = [&] (long num, long rotation, int digit) {
            // check if number is equal to rotated version
            // if not, increase the count
            if (num != rotation)
                ++cnt;
            // generate next possible numbers leading with num
            // and continue checking
            for (auto d : valid) {
                if (num*10 + d > N)
                    break;
                else
                    helper(num*10 + d, mapping[d]*pow(10, digit) + rotation, digit + 1);
            }
        };
        // since we want to avoid duplications, we shouldn't have 0 as our leading integer
        // as 00008 would be same as 8
        helper(1, 1, 1);
        helper(6, 9, 1);
        helper(8, 8, 1);
        helper(9, 6, 1);
        return cnt;
    }
};
/*
Instead of checking all numbers from 1 to N to see if they contain valid digits and have
rotated version != original, we generate all numbers < N using only valid digits and each time
check if rotated version != original.
*/
