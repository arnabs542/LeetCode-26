// Tags: Sliding-window DP Google
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int min_sum  = numeric_limits<int>::max();
        int left = 0, cur = 0, total = 0, n = cardPoints.size();
        for (int right = 0; right < n; ++right) {
            total += cardPoints[right];
            cur += cardPoints[right];
            if (right - left + 1 > n - k)
                cur -= cardPoints[left++];
            if (right - left + 1 == n - k)
                min_sum = min(min_sum, cur);
        }
        return total - min_sum;
    }
};
/*
Problem can be translated to "Find the smallest subarray sum of length len(cardPoints) - k"
The rest of the array will return the maximum score that can be obtain.
*/



// Time limit exceeded
// Reusing 1770-maximum-score-from-performing-multiplication-operations
class Solution {
    int dp(vector<int>& cardPoints, vector<vector<int>>& memo, int i, int j, int k) {
        int n = cardPoints.size();
        int taken = (i - 0) + n - 1 - j;
        if (taken == k)
            return 0;
        if (!memo[i][j - (n - k)]) {
            memo[i][j - (n - k)] = max(cardPoints[i] + dp(cardPoints, memo, i + 1, j, k),
                                      cardPoints[j] + dp(cardPoints, memo, i, j - 1, k));
        }
        return memo[i][j - (n - k)];
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<vector<int>> memo(n, vector<int>(n));
        return dp(cardPoints, memo, 0, n - 1, k);
    }
};


// To do: O(n) Dp
