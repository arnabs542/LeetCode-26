// Tags: String Greedy WC225
// Time: O(m + n)
// Space: O(26)
class Solution {
public:
    int minCharacters(string a, string b) {
        // A, B
        vector<int> cnt1(26), cnt2(26);
        int m = a.length(), n = b.length();
        for (char c : a)
            ++cnt1[c - 'a'];
        for (char c : b)
            ++cnt2[c - 'a'];
        int res = m + n;
        for (int i = 0; i < 26; ++i) {
            // condition 3:
            // total - number of most frequent count (not prefix sum)
            res = min(res, m + n - cnt1[i] - cnt2[i]);
            if (i > 0) {
                // update prefix sum
                cnt1[i] += cnt1[i - 1];
                cnt2[i] += cnt2[i - 1];
            }
            if (i < 25) {
                /* think a to z is a stone spread on a line, from left to right.
                E.g. for condition 1:
                If I pick a stone pile (imagine red line at ith position), to make all
                stones in A to be smaller than B, we will need to move all the piles
                on the right to red line in A to left of red line, Also, make all the
                piles in B to the right of the red line.
                
                We cant move stones in b to be on the right of z as there is no character
                greater than z. Therefore, we don't consider z as the pivot point.
                */
                // condition 1:
                // #_stone_at_right_in_A (after ith position) + #_stone_at_left_in_B
                res = min(res, m - cnt1[i] + cnt2[i]);
                // condition 2:
                // #_stone_at_right_in_B (after ith position) + #_stone_at_left_in_A
                res = min(res, n - cnt2[i] + cnt1[i]);
                // 
            }
        }
        return res;
    }
};
