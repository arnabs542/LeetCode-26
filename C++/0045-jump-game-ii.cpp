// Tags: Array Greedy Top-100-liked
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0;
        int start = 0, end = 0;
        // in worst case the previous level will end just before nums[n - 1]
        while (end < n - 1) {
            // increment before as at some point we return without
            // reaching the end of the loop
            ++step;
            // maxend will be atleast the star of the next level
            int maxend = end + 1;
            for (int i = start; i <= end; ++i) {
                if (i + nums[i] >= n - 1)
                    return step;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};

/*
The problem has an implicit BFS structure.

We keep two pointers start and end that record the current range (level) of 
the starting nodes. 

Each time after we make a move (step to the next level), update start to be
end + 1 and end to be the farthest index that can be reached in 1 move from
the current [start, end].

(A level contains all indices that were reachable by indices in the previous
level in just 1 jump)
*/



// Time: O(n^2)
// Space: O(n)
// Time limit exceeded
// Dp solution
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (auto i = 1; i < nums.size(); ++i) {
            for (auto j = i - 1; j >= 0; --j) {
                if (nums[j] >= i - j)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};

// dp[i] = dp[j] + 1 if (j - i <= nums[j])
