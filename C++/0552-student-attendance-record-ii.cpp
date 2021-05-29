// Tags: DP Google
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int checkRecord(int n) {
        if (n == 1)
            return 3;
        int mod = 1000000007;
        long long *A = new long long[n + 1];
        long long *P = new long long[n + 1];
        long long *L = new long long[n + 1];
        // P, L, A
        P[0] = L[0] = A[0] = 1;
        // PL, AL, LL
        L[1] = 3;
        // PA, LA
        A[1] = 2;
        // PLA, LLA, PPA, LPA
        A[2] = 4;
        for (int i = 1; i < n; ++i) {
            // we need to do mod for every 2-middle-result-addition.
            // or we can change variables to long long
            P[i] = (P[i - 1] + A[i - 1] + L[i - 1]) % mod;
            if (i >= 2)
                L[i] = (P[i - 1] + A[i - 1] + A[i - 2] + P[i - 2]) % mod;
            if (i >= 3)
                A[i] = (A[i - 1] + A[i - 2] + A[i - 3]) % mod;
        }
        return (A[n - 1] + P[n - 1] + L[n - 1]) % mod;
    }
};
/*
At every length, there can be three different states of possible attendance records that
will be regarded as rewardable.
P[i] = total no. of rewardable attendance records ending with 'P' with length 0....i
L[i] = total no. of rewardable attendance records ending with 'L' with length 0....i
A[i] = total no. of rewardable attendance records ending with 'A' with length 0....i

noA_P[i] = total no. of rewardable attendance records ending with 'P' with length 0....i
           and with no 'A'
noA_L[i] = total no. of rewardable attedance records ending with 'L' with length 0....i
           and with no 'A'

Recursive relation for dp[i]:

P[i] = A[i - 1] + P[i - 1] + L[i - 1] for i >= 1

L[i] = A[i - 1] + P[i - 1] + (A[i - 2] + P[i - 2]) for i >= 2

*A[i] = noA_P[i - 1] + noA_L[i - 1] for i >= 1

Base cases:
A[0] = P[0] = L[0] = 1
L[1] = 3
noA_P[0] = noA_L[0] = 1


Recursive relation for noA_P[i] and noA_L[i]:

*noA_P[i] = noA_P[i - 1] + noA_L[i - 1] for i >= 1

*noA_L[i] = noA_P[i - 1] + noA_P[i - 2] for i >= 2

Base cases (extra):
noA_L[1] = 2

Simplification:

Equations marked by * can be reduced to 
A[i] = A[i - 1] + A[i - 2] + A[i - 3] for i >= 3

Base cases (extra):
A[1] = 2
A[2] = 4

Note: read starred for more info.
*/
