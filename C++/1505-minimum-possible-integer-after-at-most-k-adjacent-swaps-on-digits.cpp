// pending
// Time: O(n^2)
// Space: O(n)
// Bubble sort like solution, time limit exceeded
class Solution {
public:
    string minInteger(string num, int k) {
        if (k <= 0)
            return num;
        int n = num.length();
        if (k >= n*(n + 1)/2) {
            sort(num.begin(), num.end());
            return num;
        }
        // bring the minimum possible integer (0 ~ 9) to front
        // call minInteger for the remaining num string
        for (int i = 0; i < 10; ++i) {
            int idx = num.find('0' + i);
            // only k swaps available
            // (digit must be at index within k
            // from 0th index)
            if (idx >= 0 and idx <= k)
                return num[idx] + 
                    minInteger(num.substr(0, idx) + num.substr(idx + 1), k - idx);
        }
        return num;
    }
};
