// Tags: WC223 Backtracking Bitmask-DP
// Time: O(k^n), in worst case, k possible choices at every node
// Space: O(n), height of tree
class Solution {
    void dfs(int i, vector<int> &jobs, int k, vector<int> &workers, int &res) {
        if (i == jobs.size()) {
            res = min(res, *max_element(workers.begin(), workers.end()));
            return;
        }
        // record tried workloads of workers
        // (for branches of current node only)
        unordered_set<int> seen;
        for (int j = 0; j < k; ++j) {
            // no need to try workload value which has already been tried (opt 1)
            if (seen.count(workers[j]))
                continue;
            // no need to try this workload if a lesser value already seen (opt 2)
            if (workers[j] + jobs[i] >= res)
                continue;
            seen.insert(workers[j]);
            // assign current job to this worker
            workers[j] += jobs[i];
            dfs(i + 1, jobs, k, workers, res);
            // backtrack
            workers[j] -= jobs[i];
        }
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k, 0);
        int res = INT_MAX;
        // reverse sort all the jobs so that we are more likely to exit/prune earlier
        // sort(jobs.begin(), jobs.end(), greater<int>()); (opt 3)
        dfs(0, jobs, k, workers, res);
        return res;
    }
};
/*
It is easy to get TLE, so how should we cut some branches and 
speed up the searching process?
=> Three optimizations as shown above.
*/



// Time: O(k*(3^n))
// Space: O(k*2^n)
// Bitmask Dp
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        const int n = jobs.size();
        // 2^n subsets possible for n jobs
        vector<int> sums (1<<n);
        for (int b = 0; b < 1<<n; ++b) {
            // iterating all bits of bitmask b
            for (int i = 0; i < n; ++i)
                if (b & 1<<i)
                    sums[b] += jobs[i];
        }
        // total k workers & 2^n subsets
        vector<vector<int>> dp(k + 1, vector<int>(1 << n));
        // base case
        for (int b = 0; b < 1<<n; ++b)
            dp[1][b] = sums[b];
        
        for (int i = 2; i <= k; ++i) {
            for (int b = 1; b < 1<<n; ++b) {
                // obviously with i - 1 workers answer will be larger
                dp[i][b] = dp[i - 1][b];
                for (int sb = b; sb; sb = (sb - 1)&b) {
                    // b - sb always valid as sb is a subset of b
                    // (i.e. bits set in sb are also set in b)
                    dp[i][b] = min(dp[i][b], max(sums[b - sb], dp[i - 1][sb]));
                }
            }
        }
        // all workers and all jobs (0b111111...n times)
        return dp[k][(1<<n) - 1];
    }
};
/*
dp[i][b] = minimum possible maximum working time for assigning
           a subset b of the jobs to i workers.
           (where each bit of bitmap b represent a job present
            in the subset)
            
dp[i][b] = min {max(dp[i - 1][sb], sums[b - sb])}, over all subsets sb of b
           (assign subset b - sb to ith worker and rest i.e subset sb to
           i - 1 workers)
Base case:
    dp[1][b] = sums(b), where sums is the sum of job time of all jobs
    represented by bits in bitmap b

Note: i is not like k of knapsack. When we say i, we mean the 
      absolute number i not 0....i.
*/
