// Tags: WC230 Greedy
// Time: O(n log n + m log m), where n and m are sizes of our arrays
// Space: O(m + n)
// Using two heaps
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // can't equalize the arrays even after changing one of the arrays 
        // to all 6's
        if (nums2.size() * 6 < nums1.size() || nums1.size() * 6 < nums2.size())
            return -1;
        // sum1 stores smaller sum and sum2 stores larger sum
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 > sum2)
            swap(nums1, nums2);
        priority_queue<int, vector<int>, greater<int>> min_heap(nums1.begin(), nums1.end());
        priority_queue<int> max_heap(nums2.begin(), nums2.end());
        int cnt = 0, diff = abs(sum1 - sum2);
        // stop when diff becomes either = 0 or < 0
        while (diff > 0) {
            ++cnt;
            if (min_heap.empty() || (!max_heap.empty() && 
                    max_heap.top() - 1 > 6 - min_heap.top())) {
                // make it 1, decrease 
                diff -= max_heap.top() - 1;
                max_heap.pop();
            } else {
                // make it 6, increase
                diff -= 6 - min_heap.top();
                min_heap.pop();
            }
            // diff may become negative (for last change), in that case we stop and say
            // instead of doing full increase/decrease, we increase/decrease by
            // smaller value 
        }
        return cnt;
    }
};
/*
Intuition:
We can increase sum of the smaller array by upto 5 per move (if we have 1 in there, 1 -> 6).
We can decrease sum of the larger array by upto 5 per move (if we have 6 in there, 6 -> 1).

1. Use min heap for the smaller array and max heap for larger array
2. Pull a value from one of the heaps (pick a heap that give us most points)
3. Repeat till the sum of two arrays is equalized.


Why we use heaps instead of sorting?
Heaps are great when you do not know how many elements you'll need to process.
The runtime complexity of a heap is O(k log n), where k is the number of pop operations
*/


// Time: O(m + n)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 > sum2)
            swap(nums1, nums2);
        // number of instances of increase change of smaller array
        // and decrease change of larger array
        int cnt[6] = {}, diff = abs(sum1 - sum2);
        // no of changes
        int res = 0;
        // increase changes of smaller array
        for (int n : nums1)
            ++cnt[6 - n];
        // decrease changes of larger array
        for (int n : nums2)
            ++cnt[n - 1];
        for (int i = 5; i > 0 && diff > 0; --i) {
            // available instances could be more than required
            int take = min(cnt[i], diff / i + (diff % i != 0));
            diff -= take * i;
            res += take;
        }
        return res;
    }
};
/*
If you look heap solution, we are not concerned about increase or decrease,
we only see how much value can be changed.

so lets declare an array to record counts of these changes [0 to 5].

Also, in heap solution, we always make greater changes first i.e we go from [5 to 0].

Why add (diff % i != 0) ?
[6,6] -> sum2 = 12
[1]   -> sum1 = 1
    0 1 2 3 4 5
cnt [         3]

ans = [1 1]
      [2]
=> if remainder != 0, have to make one more change
*/



// First attempt, wrong solution
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int inf = 1e7;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int sum = 0;
                    // moving i
                    for (int l = 1; i - l >= 1 && sum <= 6; ++l) {
                        sum += nums1[i - l + 1 - 1];
                        dp[i][j] = min(dp[i][j], dp[i - l][j - 1] + 1);
                        // if (sum == nums2[j - 1])
                        //     dp[i][j] = min(dp[i][j], dp[i - l][j - 1]);
                    }
                    sum = 0;
                    // moving j
                    for (int l = 1; j - l >= 1 && sum <= 6; ++l) {
                        sum += nums2[j - l];
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + 1);
                        // if (sum == nums1[i - 1])
                        //     dp[i][j] = min(dp[i][j], dp[i - 1][j - l]);
                    }
                }
            }
        }
        if ((m == 1 && n <= 6) || (n == 1 && m <= 6))
            dp[m][n] = min(dp[m][n], m + n);
        return dp[m][n] == inf ? -1 : dp[m][n];
    }
};
