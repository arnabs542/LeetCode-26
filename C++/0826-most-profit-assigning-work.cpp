// Tags: Two-pointers Amazon
// Time: O(DlogD + WlogW)
// Space: O(D)
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); ++i)
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        // current index for jobs & best profit so far
        int i = 0, best = 0, res = 0;
        for (int& ability : worker) {
            // ability of next worker will be same or more so can atleast
            // do the job did by previous worker (therefore i never goes back)
            
            // keep moving while condition satisfies & record the maximum
            // profit seen so far
            while (i < jobs.size() && ability >= jobs[i].first)
                best = max(best, jobs[i++].second);
            res += best;
        }
        return res;
    }
};
/*
1. zip difficulty and profit as jobs.
2. sort jobs and sort 'worker'.
3. use 2 pointers. For each worker, find his maximum profit best
   he can make under his ability.
   
Because we have sorted jobs and worker,
we will go through two lists only once.
this will be only O(D + W).
O(DlogD + WlogW), as we sort jobs
*/
