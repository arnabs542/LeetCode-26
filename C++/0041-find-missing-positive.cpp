// Tags: Array Top-100-liked Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;
        int n = nums.size(), containsOne = 0;
        
        // Step 1
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                containsOne = 1;
            } else if (nums[i] < 1 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        if (containsOne == 0)
            return 1;
        
        // Step 2
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
                nums[index] *= -1;
        }
        
        // Step 3
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        
        return n + 1;
    }
};

/*
The range of possible answers is [1..n] if an integer is missing,
and if an integer is not missing then the answer is n+1.

1. Ignore all numbers <= 0 and > n since they are outside the range
   of possible answers.
2. For all other integers < n+1, mark their bucket (cell) to 
   indicate the integer exists. 
   (For marking, we make the integer
   at index (integer - 1) negative), -1 since indices are 0-based
   (Integers [1...n] are mapped to indices [0....n-1])
3. Find the first cell not marked, that is the first missing integer.
   If you did not find an unmarked cell, there was no missing integer,
   so return n+1. 
   (Since indices are sorted, when we interate from 0 to n -1
   we check numbers from lowest to highest [1 to n])

Note: This algorithm is along the same lines as the Brute force solution.
*/



// Time: O(n)
// Space: O(n)
// Brute-force solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numset(nums.begin(), nums.end());
        // At max there could be 1 2 3 ......n positive integers
        // so the first missing integer would be n + 1
        for (int i = 1; i <= n + 1; ++i) {
            if (!numset.count(i))
                return i;
        }
        return -1;
    }
};
