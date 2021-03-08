// Tags: Array Amazon
// Time: O(hlogh + wlogw)
// Space: O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        // find maximum height between first height & last height
        int max_h = max(hCuts[0], h - hCuts.back());
        // first maximum width between first width & last width
        int max_v = max(vCuts[0], w - vCuts.back());
        // find maximum height among rest of heights
        for (int i = 0; i < hCuts.size() - 1; ++i) {
            max_h = max(max_h, hCuts[i + 1] - hCuts[i]);
        }
        // find maximum width among rest of widths
        for (int j = 0; j < vCuts.size() - 1; ++j) {
            max_v = max(max_v, vCuts[j + 1] - vCuts[j]);
        }
        return ((long)max_h * max_v) % 1000000007;
    }
};
/*
1. Find heights of pieces if we only perform the horizontal cuts. Say this array is heights[].
2. Find lengths of pieces if we only perform the vertical cuts. Say this arrays is widths[].
3. Find max of heights[] and widths[].
4. Multiply those two max and take mod 10e7.
5. Return the answer

Note: No need to worry about multiplying each height with corresponding width as every height
creates a valid area with every width.
*/
