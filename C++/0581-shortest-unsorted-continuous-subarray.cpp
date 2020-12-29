// Tags: Array Top-100-liked
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), minVal = INT_MAX, maxVal = INT_MIN;
        int end = -2, beg = -1;
        for (int i = 0; i < n; ++i) {
            // moving left to right (consider subarray nums[:end + 1])
            maxVal = max(maxVal, nums[i]);
            if (nums[i] < maxVal)
                end = i;
            
            // moving right to left (consider subarray nums[beg: ])
            minVal = min(minVal, nums[n - 1 - i]);
            if (nums[n - 1 - i] > minVal)
                beg = n - 1 - i;
        }
        return end - beg + 1;
    }
};

/*
Whenever we come across a value A[i] that is smaller than the current max,
we know that the unsorted subarray AT LEAST needs to end here.
Similarly, whenever we come across a value A[n-1-i] that is larger than the
current min, we know that the unsorted subarray AT LEAST needs to start here.

Unsorted [2,6,4,8,10,9,15]

Sorted [2 4 6 8 9 10 15]

In sorted array, conditions (nums[i] < maxVal) and (nums[n - 1 - i] > minVal)
will not ever satisfy.
*/
