// Tags: Array Backtracking Bit-manipulation Amazon
// Time: O(n*2^n)
// Space: O(n*2^n), to keep all the subsets of length n,
// since each of n elements could be present or absent.
// Recursion (backtracking)
class Solution {
    vector<vector<int>> res;
    void helper(vector<int>& nums, int i, vector<int>& cur) {
        // capture previous result
        res.push_back(cur);
        // continue adding more numbers starting from i
        for (int j = i; j < nums.size(); ++j) {
            cur.push_back(nums[j]);
            helper(nums, j + 1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        helper(nums, 0, cur);
        return res;
    }
};



// Time: O(n*2^n), when generating a new subset, we are visiting all previously
//       generated subsets
// Space: O(n*2^n)
// Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {{}}; // add an empty subset
        for (int num : nums) {
            // current number of subsets
            int sz = res.size();
            for (int i = 0; i < sz; ++i) {
                // create a copy
                res.push_back(res[i]);
                // add current element to that copy
                res.back().push_back(num);
            }
            
        }
        return res;
    }
};
/*
Using [1, 2, 3] as an example, the iterative process is like:

    Initially, one empty subset [[]]
    Adding 1 to []: [[], [1]];
    Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
    Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/



// Time: O(n*2^n)
// Space: O(n*2^n)
// Bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // n is less than 31 so signed int can be used, 1 <= n <= 10
        int n = nums.size();
        vector<vector<int>> res(1 << n);
        for (int mask = 0; mask < 1 << n; ++mask) {
            for (int j = 0; j < n; ++j) {
                if (mask & 1 << j) { // or (mask >> j) & 1
                    // jth bit is set
                    res[mask].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};
/*
To get all the possible subsets, we just need to exhaust all the possible combinations of the numbers.
And each number has only two possibilities: either in or not in a subset. 
And this can be represented using a bit.
*/
