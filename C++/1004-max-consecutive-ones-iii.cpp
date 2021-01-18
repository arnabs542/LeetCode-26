// Tags: Sliding-window Amazon
// Time: O(n)
// Space: O(1)
// Similar to 0340-longest-substring-with-at-most-k-distinct-characters
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, zeros = 0;
        for (int left = 0, right = 0; right < A.size(); ++right) {
            if (A[right] == 0)
                ++zeros;
            while (zeros > K) {
                if (A[left] == 0)
                    --zeros;
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
