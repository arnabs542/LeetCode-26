// Tags: Dp Binary-search Amazon
// Time: O(m*(n^2))
// Space: O(m*n)
// Somewhat similar to 1335-minimum-difficulty-of-a-job-schedule
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        // 1 indexed for both dimensions
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 1 indexed prefix sum where prefix[i] = nums[1] +......+ nums[i]
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
            // or preSum[i] = preSum[i - 1] + nums[i - 1]
            // for i = 1 to n
        }
        dp[0][0] = 0;
        for (int k = 1; k <= m; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j)
                    dp[k][i] = min(dp[k][i], max(dp[k - 1][j], preSum[i] - preSum[j]));
            }
        }
        return dp[m][n];
    }
};

/*
dp[k][i] = minimum largest subarray sum for splitting
nums[0....i] into k parts.

dp[k][i] = min over 0<=j<=i {max(dp[k - 1][j],
    nums[j + 1]......nums[i])}

Base case:
dp[0][0] = 0, rest are INFINITY
*/



// Time:  O(logs * n), s is the sum of nums
// Space: O(1)
// Binary Search + Greedy
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // smallest possible value of largestSum
        int left = *max_element(nums.begin(), nums.end());
        // largest possible value of largestSum
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        // O(logs)
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (split(nums, mid) <= m) {
                // (region of interest)
                ans = mid;
                // decreasing largestSum to increase subarrays count
                right = mid - 1;
            } else {
                // increasing largestSum to decrease subarrays count
                left = mid + 1;
            }
        }
        return ans;
        
    }
private:
    // returns the numbers of subarrays nums can be split
    // into for the given largestSum, O(n)
    int split(vector<int> &nums, int largestSum) {
        int subarrays = 1;
        int tmpSum = 0;
        for (const auto &num: nums) {
            if (tmpSum + num > largestSum) {
                tmpSum = num;
                ++subarrays;
            } else
                tmpSum += num;
        }
        return subarrays;
    }
};
