// Tags: Array Hash-table Amazon
// Time: O(n)
// Space: O(n)
// Same idea as 0437-path-sum-iii
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_cnt;
        sum_cnt[0] = 1;
        int res = 0, running_sum = 0;
        for (int num : nums) {
            running_sum += num;
            if (sum_cnt.count(running_sum - k))
                res += sum_cnt[running_sum - k];
            ++sum_cnt[running_sum];
        }
        return res;
    }
};
/*
If the cumulative sum upto two indices is at a difference
of k, the sum of elements lying in between those indices
is k. 

For each index i, we have to iterate j backwards as
there may be multiple instances (due to negative integers)
of cum_sum[i] - cum_sum[j]== k.

E.g. Both of these have running sum 9. (say k = 8)
[4 3 2 | -2 2 4 4]  
[4 3 2 -2 2 | 4 4]
ans = 2

We can instead use a hash map to register the num of times
a particular cummulative sum appears.
*/
