// Tags: Math Hash-table
// Time: O(n)
// Space: O(n)
// Reusing 0560-subarray-sum-equal-k and
// 1010-pair-of-songs-with-total-durations-divisible-by-60
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // running sum to index where it was last seen
        unordered_map<int, int> mp;
        mp.insert({0, -1});
        int running_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            running_sum += nums[i];
            if (k != 0)
                running_sum %= k;
            auto prev = mp.find(running_sum);
            // seen before and subarray of size atleast 2
            // (prev->second != i - 1)
            if (prev != mp.end()) {
                if (i - prev->second > 1)
                    return true;
            } else {
                mp[running_sum] = i;
            }
        }
        return false;
    }
};
/*
We iterate through the input array exactly once,
keeping track of the running sum mod k of the elements in the process.

If we find that a running sum value at index j has been previously seen
before in some earlier index i in the array, then we know that the
sub-array (i,j] contains a desired sum.

running sum values can only be between 0 to k - 1 (circular fifo)
so if we are at j and the same running sum was seen at index i earlier,
subarray [i, j] contains the desired sum.

In other words, (a - (n * k)) % k is same as (a % k).
For e.g. in case of the array [23,2,6,4,7]
the running sum is [23,25,31,35,42] 
and the remainders are [5,1,1,5,0]. 
We got remainder 5 at index 0 and at index 3. 
That means, in between these two indexes we must have added a number
which is multiple of the k.
*/
