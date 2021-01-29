// Tags: WC222 Greedy
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto t : target)
            m[t] = m.size();
        // Monotonic stack (stack which is either strictly increasing or decreasing)
        vector<int> tails;
        for (auto n : arr) {
            auto it = m.find(n);
            if (it != m.end()) {
                // it->second gives index
                if (tails.empty() || tails.back() < it->second)
                    tails.push_back(it->second);
                else
                    *lower_bound(tails.begin(), tails.end(), it->second) = it->second;
            }
            // ignore numbers not in target
        }
        return target.size() - tails.size();
    }
};

/*
We want to find longest common subsequence but dp solution gives TLE.

Since the numbers in target are unique (we are finding longest sequence
maintainig order of target), we can re-map them to the increasing numbers,
i.e. target: [6,4,8,1,3,2] => [0, 1, 2, 3, 4, 5]

Now arr:
[4,7,6,2,3,8,6,1] becomes [1, 0, 5, 4, 2, 0, 3] (ignoring numbers not in target).

Now, we can find the longest increasing sequence in arr - 
we can do it in O(n log n) using mono-stack (insertion sort approach, maintaing
active list).

That subsequence is what we are going to take from arr. The rest needs to be inserted.
*/



// Time: O(n^2)
// Space: O(n^2)
// Reusing 1143-longest-common-subsequence
// Time limit exceeded
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = arr.size(), n = target.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (arr[i - 1] == target[j - 1]) ? 
                    dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[m][n];
    }
};

/*
dp[m][n] gives the largest common subsequence between arr[:n] and target[:m]
therefore the minimum operations needed to make largest common subsequence == n
are n - dp[m][n].
*/
