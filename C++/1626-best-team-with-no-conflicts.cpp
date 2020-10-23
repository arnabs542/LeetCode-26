// Tags: WC211
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> dp(n);
        vector<pair<int, int>> player;

        for (int i = 0; i < n; ++i) {
            player.push_back({ages[i], scores[i]});
        }

        sort(player.begin(), player.end(), greater<>());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int score = player[i].second;
            dp[i] = score;
            for (int j = 0; j < i; ++j) {
                if (player[j].second >= player[i].second) {
                    // no conflict
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


/*
first sort the players by their age so that we don't have to always check both
the scores and the age to see whether these two players can be in the same team

dp[i] stores the maximum score that can be obtained when i-th player is
included and all other players are between indices 0 and i-1
*/
