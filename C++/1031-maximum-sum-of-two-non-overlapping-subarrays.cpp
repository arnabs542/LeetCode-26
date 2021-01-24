// Tags: Array Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // prefix sum
        for (int i = 1; i < A.size(); ++i)
            A[i] = A[i - 1] + A[i];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            // previous Lsum could be Lmax
            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
            // previous Msum could be Mmax
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            // Lmax + Msum, Mmax + Lsum
            res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return res;
    }
};
/*
Lsum, sum of the last L elements ending at index i
Msum, sum of the last M elements ending at index i

Lmax, max sum of contiguous L elements before the last M elements.
Mmax, max sum of contiguous M elements before the last L elements
*/
