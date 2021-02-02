// Tags: Two-pointers Amazon
// Time: O(n)
// Space: O(n)
// Two-pass solution
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> up(n), down(n);

        for (int i = n - 2; i >= 0; --i)
            if (arr[i + 1] < arr[i])
                down[i] = down[i + 1] + 1;
            // else down[i] = 0
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && arr[i] > arr[i - 1])
                up[i] = up[i - 1] + 1;
            // else up[i] = 0
            if (up[i] && down[i])
                res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};
/*
We take one forward pass to count up hill length (to every point).
We take another backward pass to count down hill length (from every point).
(excluding current point)

Finally a pass to find max(up[i] + down[i] + 1) where up[i] and down[i] 
should be positives.
*/



// Time: O(n)
// Space: O(1)
// One-pass solution
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), res = 0;
        // count up hill length & count down
        // hill length for current mountain
        int up = 0, down = 0;
        for (int i = 1; i < n; ++i) {
            // reset counters when
            // 1. values remain stadnant
            // or 2. we start going up hill again after coming down a hill
            if (arr[i] == arr[i - 1] || down > 0 && arr[i] > arr[i - 1])
                up = down = 0;
            up += arr[i] > arr[i - 1];
            down += arr[i] < arr[i - 1];
            if (up && down)
                res = max(res, up + down + 1);
        }
        return res;
    }
};
