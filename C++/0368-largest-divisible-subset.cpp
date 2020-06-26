// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty())
            return {}; // or return vector<int>();
        vector<int> dp (nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        sort(nums.begin(), nums.end());
        int largest_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[largest_idx] < dp[i]) {
                largest_idx = i;
            }
        }
        vector<int> result;
        for (int i = largest_idx; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
            //or .emplace
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


// Notes:
// dp[i]: the size of the largest distinct subset of the first
// i+1 numbers including nums[i]
