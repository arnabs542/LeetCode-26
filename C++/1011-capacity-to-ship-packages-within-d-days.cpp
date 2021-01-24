// Tags: Array Binary-search Amazon
// Time: O(nlogs), s is the total sum of weights
// Space: O(1)
// Same as 0410-split-array-largest-sum
// Binary search solution
class Solution {
    int countDays(vector<int>& weights, int totalCap) {
        int curCap = 0, cnt = 1;
        for (const auto& w : weights) {
            curCap += w;
            if (curCap > totalCap) {
                curCap = w;
                ++cnt;
            }
        }
        return cnt;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        auto r = accumulate(weights.begin(), weights.end(), 0);
        auto l = max(r/D, *max_element(weights.begin(), weights.end()));
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (countDays(weights, mid) <= D) {
                ans = mid;
                // decrease capacity to increase number of days
                r = mid - 1;
            } else {
                // increase capacity to decrease number of days
                l = mid + 1;
            }
        }
        return ans;
    }
};
/*
Intuition:
The largest capacity (r) we may even need is the sum of weights
of all packages.
The smallest capacity (l) is the weight of the largest package.
Our result is within this interval.
    Optimization: the smallest capacity cannot be less than r / D, 
    which reduces the search interval if we have a lot of small packages

Algorithm:
We use binary search to find the minimum capacity. For each capacity
we analyze, we count the number of days required to ship all packages.

We decrease the capacity if it takes less days than D, and increase
otherwise. Note that, when the number of days equals D, this algorithm
keeps decreasing the capacity while it can, therefore finding the
smallest capacity required.
*/

/* Dp solution gives TLE, O(D*(n^2)) */
