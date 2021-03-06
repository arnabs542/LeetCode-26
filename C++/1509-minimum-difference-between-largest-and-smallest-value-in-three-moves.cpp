// Tags: Array Sort Google
// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        if (n < 5)
            return 0;
        sort(nums.begin(), nums.end());
        for (int k = 1; k <= 4; ++k)
            res = min(res, nums[n - k] - nums[4 - k]);
        return res;
    }
};
/*
We have 4 cases:

E.g.

A = [1, 5, 6, 13, 14, 15, 16, 17]
n = 8

Case 1: kill 3 biggest elements

All three biggest elements can be replaced with 14 (next biggest element)
[1, 5, 6, 13, 14, 15, 16, 17] -> [(1), 5, 6, 13, (14), 14, 14, 14]
== can be written as A[n-4] - A[0] == (14-1 = 13)


Case 2: kill 2 biggest elements + 1 smallest elements

[1, 5, 6, 13, 14, 15, 16, 17] -> [5, (5), 6, 13, 14, (15), 15, 15]
== can be written as A[n-3] - A[1] == (15-5 = 10)


Case 3: kill 1 biggest elements + 2 smallest elements

[1, 5, 6, 13, 14, 15, 16, 17] -> [6, 6, (6), 13, 14, 15, (16), 16]
== can be written as A[n-2] - A[2] == (16-6 = 10)


Case 4: kill 3 smallest elements

[1, 5, 6, 13, 14, 15, 16, 17] -> [13, 13, 13, (13), 14, 15, 16, (17)]
== can be written as A[n-1] - A[3] == (17-13 = 4)

OR  A[n - k] - A[4 - k] for k = 1 to 4

Answer is minimum of all these cases!
*/



// Time: O(nlog4)
// Space: O(1)
// Partial sorting
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 5)
            return 0;
        partial_sort(nums.begin(), nums.begin() + 4, nums.end()); // nlog4
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end()); // n - 4 (average)
        sort(nums.end() - 4, nums.end()); // 4log4
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2],
                    nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
