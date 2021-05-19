// Tags: DP Sliding-window Google
// Time: O(n)
// Space: O(n)
// Sliding window, optimized
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int res = INT_MAX, sum = 0;
        // best[i] = minimum length of sub-array of sum = target seen so far in arr[:i]
        vector<int> best(arr.size(), INT_MAX);
        for (int left = 0, right = 0; right < arr.size(); ++right) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            // capture the best result seen so far
            if (right > 0)
                best[right] = best[right - 1];
            if (sum == target) {
                // best[left - 1] since [left , right] denotes current window
                if (left > 0 && best[left - 1] != INT_MAX)
                    res = min(res, best[left - 1] + right - left + 1);
                best[right] = min(best[right], right - left + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
/*
We can use sliding-window approach as unlike 0560-subarray-sum-equal-k, there
aren't any 0 or negative values in the array.
*/



// Time: O(nlogn)
// Space: O(n)
// Sliding window, very first solution
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int res = INT_MAX, sum = 0;
        // key: length of window (having sum = target)
        // value: earliest index where such window ends
        map<int, int> mp;
        for (int left = 0, right = 0; right < arr.size(); ++right) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = right - left + 1;
                // find first window, not overlapping with the
                // current window
                for (auto kvp : mp) {
                    if (kvp.second < left) {
                        res = min(res, kvp.first + len);
                        break;
                    }
                }
                if (mp.count(len))
                    mp[len] = min(mp[len], right);
                else
                    mp[len] = right;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// Eg. [1 1 1 4 2 1 2], target = 3



// To do: Dp general solution, N non-overlapping sub-arrays
