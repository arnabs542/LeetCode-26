// Tags: WC215 Two-pointers
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // (stores prefix sum but mapping sum to index instead)
        // telling no of elements removed to get sum
        // left[0] = 0 (0 removed to get sum = 0)
        int res = INT_MAX;
        unordered_map<int, int> left;
        for (int l = 0, sum = 0; l < nums.size() && sum <= x; ++l) {
            left[sum] = l;
            sum += nums[l];
        }
        for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r) {
            // no of elements removed from left to get (x - sum), if found
            // O(1) operation
            auto it = left.find(x - sum);
            // if found & it doesn't go past right pointer
            // (sum taken upto r + 1 (previous pointer position))
            if (it != left.end() && it->second <= r + 1)
                res = min(res, (int)nums.size() - r - 1 + it->second);
            sum += nums[r];
        }
        return res == INT_MAX ? -1 : res;
    }
};

/*
Seems like a O(k*n^2) Dp problem, but the constraints are too large.
*/



// Time: O(n)
// Space: O(n)
// Two sum like solution
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // target is totalSum - x
        int target = accumulate(nums.begin(), nums.end(), -x);
        
        // since all elements are positive, we have to take all of them
        if (target == 0)
            return nums.size();
        
        // prefix sum to array index
        unordered_map<int, int> lookup;
        
        // length of longest subarray with sum == target = totalSum - x
        int res = INT_MIN;
        int sum = 0;
        lookup[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (lookup.count(sum - target))
                res = max(res, i - lookup[sum - target]);
            lookup[sum] = i;
        }
        return res == INT_MIN ? -1 : (int)nums.size() - res;
    }
};

/*
If it exists an answer, then it means we have a subarray in the middle of
original array whose sum is == totalSum - x

If we want to minimize our operations, then we should maximize the length 
of the middle subarray.

Then the question becomes: Find the Longest Subarray with Sum Equals to
TotalSum - X
*/
