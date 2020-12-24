// Tags: DP WC219 Sort
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &c: cuboids)
            sort(c.begin(), c.end());
        int n = cuboids.size(), res = 0;
        // for cases when i = 0
        cuboids.push_back({0, 0, 0});
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n + 1);
        for (int j = 1; j <= n; ++j) {
            // i is starting from 0 so that we get a case when we only select jth and nothing else
            for (int i = 0; i < j; ++i) {
                if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
                    dp[j] = max(dp[j], dp[i] + cuboids[j][2]);
                    res = max(res, dp[j]);
                }
            }
        }
        return res;
    }
};

/*
Similar to 0300-longest-increasing-subsequence

dp[j] = maximum height from 1th upto jth cuboid by necessarily selecting jth cuboid

cuboids[0] = {0, 0, 0}

dp[j] = (0 < i < j) max(dp[j], dp[i] + cuboids[j][2]) if cuboid j can be placed below cuboid i

Base case:
    dp[0] = 0;

We can place cuboid i on cuboid j if
width[i] <= width[j] and length[i] <= length[j] and height[i] <= height[j].

This condition will hold, after we sort each cuboid length,
that is,
small[i] <= small[j] and mid[i] <= mid[j] and big[i] <= big[j]
*/
