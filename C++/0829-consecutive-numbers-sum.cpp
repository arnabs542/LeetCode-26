// Tags: Math Amazon
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        for (int k = 2; k*(k + 1) <= 2*N; ++k) {
            if ((N - k*(k + 1)/2) % k == 0)
                ++count;
        }
        return count;
    }
};
/*
N = (x+1) + (x+2) + ... + (x+k)
N = kx + k(k+1)/2
kx = N - k(k + 1)/2

So, we can calculate the RHS for every value of k and
if it is a multiple of k then we can construct a sum
of N using k terms starting from x

At max, RHS could be 0
N = k*(k + 1)/2
k*(k + 1) = 2N
*/
