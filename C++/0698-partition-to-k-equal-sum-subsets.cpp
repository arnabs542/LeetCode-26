// Tags: Bitmask-DP DFS Amazon
// Time:  O(k^n), in worst case, k possible choices at every node
// Space: O(n), height of tree
// Dfs + Pruning
// Similar to 1723-find-minimum-time-to-finish-all-jobs
class Solution {
    bool dfs(vector<int> &nums, vector<int> &sets, int target, int i) {
        // since we only added number to a set if sum remained <= target
        // so if i reaches nums.size(), it means all sets have equal sum values
        // (if one had value greater than the other, it wouldn't have 
        // reached i == nums.size())
        if (i == nums.size())
            return true;
        unordered_set<int> seen;
        for (int j = 0; j < sets.size(); ++j) {
            if (seen.count(sets[j])) // opt 3
                continue;
            if (sets[j] + nums[i] <= target) { // opt 2
                seen.insert(sets[j]);
                sets[j] += nums[i];
                if (dfs(nums, sets, target, i + 1))
                    return true;
                sets[j] -= nums[i];
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || target % k != 0 || *max_element(nums.begin(), nums.end())
            > target/k)
            return false;
        target /= k;
        vector<int> sets(k, 0);
        sort(nums.begin(), nums.end(), greater<int>()); // opt 1
        return dfs(nums, sets, target, 0);
    }
};
/* 3 optimizations for pruning */



// Time: O(n2^n)
// Space: O(2^n)
// Bitmask Dp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // int dp[1<<16];
        // fill(dp, dp + (1<<16) - 1, -1);
        vector<int> dp(1<<16, -1);
        int n = nums.size();
        dp[0] = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        // sum not exactly divisible by k
        if (totalSum % k)
            return false;

        // now we know total sum is exactly divisible by k
        // we want to find if numbers can be split into sets
        // having sum = totalsum/k
        int tar = totalSum/k;
        for (int mask = 0; mask < (1<<n); ++mask) {
            // if current state is illegal, simply ignore it
            if (dp[mask] == -1)
                continue;
            // if nums[i] is unchosen && choosing nums[i] would
            // not cross the target
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1<<i)) && dp[mask] + nums[i] <= tar)
                    dp[mask | (1<<i)] = (dp[mask] + nums[i]) % tar;
            }
        }
        return dp[(1<<n) - 1] == 0;
    }
};
/*
Note: Normally, in dp, we use other cells of dp array to update the current cell.
      However, here we are using current cell to update other cells.

dp[mask] = sum(chosen numbers) % target
           0 if the chosen numbers can be exactly divided into subsets
           of sum = target  
           OR
           x i.e sum of the numbers in the last set 
           (which doesn't have sum = target), value between 1 and target-1.

dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar (updating next using current's value)

Base case:
dp[0] = 0

Example nums = [4, 5, 2, 3, 1], k = 3, tar = 5

dp[10001] = (4 + 1) % 5 = 0
dp[10011] = (dp[10001] + 3) % 5 = 3
dp[10111] = (dp[10011] + 2) % 5 = 0
dp[11111] = (dp[10111] + 5) % 5 = 0


Example nums = [4, 4, 4, 2, 1], k = 3, tar = 5

dp[10001] = (4 + 1) % 5 = 0
dp[11001] = (dp[10001] + 4) % 5 = 4
dp[11011] = -1 since dp[11001] + 2 > target
dp[11101] = -1 since dp[11001] + 4 > target
*/



// Bitmask Dp, Failed attempt
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sums(1<<n);
        for (int b = 0; b < 1<<n; ++b)
            for (int i = 0; i < n; ++i)
                if (b & 1<<i)
                    sums[b] += nums[i];
        vector<vector<bool>> dp(k + 1, vector<bool>(1<<n));
        for (int b = 0; b < 1<<n; ++b)
            dp[1][b] = true;
        for (int i = 2; i <= k; ++i) {
            for (int b = 1; b < 1<<n; ++b) {
                for (int sb = b; sb; sb = (sb - 1)&b) {
                    dp[i][b] = dp[i][b] | (dp[i - 1][sb] && sums[sb]/(i - 1) == sums[b - sb]);
                }
            }
        }
        return dp[k][1<<n - 1];
    }
};
