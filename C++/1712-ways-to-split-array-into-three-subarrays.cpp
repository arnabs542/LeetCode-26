// Tags: WC222 Two-pointers
// Time: O(n)
// Space: O(n) for the prefix sum array - or O(1) as we reuse the input.
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), res = 0;
        partial_sum(nums.begin(), nums.end(), nums.begin());
        for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
            while (j <= i || j < n - 1 && nums[j] - nums[i] < nums[i])
                ++j;
            while (k < j || k < n - 1 && nums[n - 1] - nums[k] >= nums[k] - nums[i])
                ++k;
            res = (res + k - j) % 1000000007;
        }
        return res;
    }
};

/*
Improving the time complexity is quite easy here.

Since if the first partition moves right, the possible choices for the second partition 
i.e j & k will obviously move right to their previous locations.

So, we just need to make sure that j and k will only move forward, which result in a
linear-time solution.
*/



// Time: O(n^2)
// Space: O(n) for the prefix sum array - or O(1) as we reuse the input.
// First attempt, time limit exceeded
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), res = 0;
        partial_sum(nums.begin(), nums.end(), nums.begin());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1;
            // left most partition, keep moving as long as condition is not satisfied
            while (j < n - 1 && nums[j] - nums[i] < nums[i])
                ++j;
            int k = j;
            // right most partition, keep moving as long as condition is satisfied
            while (k < n - 1 && nums[n - 1] - nums[k] >= nums[k] - nums[i])
                ++k;
            res = (res + k - j) % 1000000007;
        }
        return res;
    }
};

/*
First we prepare the prefix sum array, so that we can compute subarray
sums in O(1).Then, we move the boundary of the first subarray left to right.

i denotes the first partition array[: i]

Now for each i, we find the leftmost (j) and rightmost (k) boundaries of the 
second subarray i.e possible choices for the second partition such that:

nums[j] - nums[i] >= nums[i] i.e. sum(mid) >= sum(left)
and
nums[sz - 1] - nums[k] >= nums[k] - nums[i] i.e. sum(right) >= sum(left)

Therefore, for a point i, we can build k - j possible subarrays satisfying the problem requirements.
*/
