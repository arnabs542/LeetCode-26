
// Tags: Array Tiktok
// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        for (; i >= 0 && digits[i] == 9 ; --i) {
            digits[i] = 0;
        }
        if (i == -1)
            digits.insert(digits.begin(), 1);
        else
            ++digits[i];
        return digits;
    }
};
