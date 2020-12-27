// Tags: Array Top-interview
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int n: nums) {
            if (n <= c1)
                c1 = n;       // c1 is min seen so far
            else if (n <= c2) // here when n > c1, i.e. n might be either c2 or c3
                c2 = n;       // n is better than the current c2, store it
            else              // here when we have/had c1 < c2 already and n > c2
                return true;  // the increasing subsequence of 3 elements exists
        }
        return false;
    }
};

/*
Just like largest increasing subsequence, we are maintaining an active
list of 3 numbers.
c1 = smallest number
c2 = second smallest number
*/



// Same as 0300-longest-increasing-subsequence
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tails;
        for (auto n: nums) {
            auto it = lower_bound(tails.begin(), tails.end(), n);
            if (it == tails.end())
                tails.push_back(n);
            else
                *it = n;
        }
        return tails.size() >=3;
    }
};



// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return count_if(dp.begin(), dp.end(), [] (int x) {return x >= 3;}) >= 1;
    }
};
