// Tags: Bit-manipulation Array Math Amazon
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // even this could be the final result
        // e.g. [0, 1]
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i)
            missing ^= i ^ nums[i];
        return missing;
    }
};
/*
We harness XOR property
    a ^ b ^ a = b
    
We know nums contains n numbers and that it is missing exactly one
number in the range [0....n-1] and that number has been replaced with
n.
So, if we initialize an integer to n and XOR it with every index and
every value present, all numbers will cancel out and we will be left
with the missing number.
*/
