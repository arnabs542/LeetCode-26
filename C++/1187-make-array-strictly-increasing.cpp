// Tags: DP Google
// Time: O(n^2 * logn), in worst case, every number of arr2 can represent a state
// Space: O(n)
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> prev_dp({{-1, 0}});
        sort(arr2.begin(), arr2.end());
        for (int num : arr1) {
            unordered_map<int, int> cur_dp;
            // Choice 1: no operation is made
            // if num already greater than some (or all) of the possible states
            // from (i - 1)th position
            // (choose minimum of all)
            for (auto kvp : prev_dp) {
                if (kvp.first < num)
                   cur_dp[num] = min(cur_dp.count(num) ? cur_dp[num] : INT_MAX, kvp.second);
            }

            // Choice 2: operation is made
            // for every states from (i - 1)th position,
            // if there is a greater number in arr2
            // (choose minimum of all + 1)
            for (auto kvp : prev_dp) {
                auto it = upper_bound(arr2.begin(), arr2.end(), kvp.first);
                if (it != arr2.end()) {
                    // *it may be equal to num
                    if (cur_dp.count(*it))
                        cur_dp[*it] = min(cur_dp[*it], kvp.second + 1);
                    else
                        cur_dp[*it] = kvp.second + 1;
                }
            }
            // opt : can merge two for loops into one

            prev_dp = cur_dp;
        }

        if (prev_dp.empty())
            return -1;
        int res = INT_MAX;
        for (auto kvp : prev_dp) {
            res = min(res, kvp.second);
        }
        return res;
    }
};
/*
At each point in our dp array, we can have multiple states.
dp[i][x] = minimum number of operations needed to make arr1[ : i] strickly increasing
           having the value x at arr1[i]
if (y < x)
    dp[i][x] = dp[i - 1][y]
else if (y < x')
    dp[i][x'] = dp[i - 1][y] + 1, x' is a value in arr2 which is just greater than y
else
    dp[i][x] = INT_MAX

Base case:
    dp[-1][-1] = 0
*/
