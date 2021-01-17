// Tags: Sliding-window Hash-table Amazon
// Time: O(n)
// Space: O(n)
class Solution {
    // returns the number of subarrays having atmost k distinct
    // integers
    int atmostK(vector<int> &A, int k) {
        unordered_map<int, int> cnt;
        int distinct = 0, res = 0;
        for (int left = 0, right = 0; right < A.size(); ++right) {
            if (cnt[A[right]]++ == 0)
                ++distinct;
            while (distinct > k) {
                if (--cnt[A[left]] == 0)
                    --distinct;
                ++left;
            }
            // right - left + 1 is the number of subarrays having
            // atmost k distinct integers ending at index right
            res += right - left + 1;
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // the difference gives number of subarrays having exactly k 
        // distinct integers
        return atmostK(A, K) - atmostK(A, K - 1);
    }
};
/*
Check notebook for better explanation.
*/
