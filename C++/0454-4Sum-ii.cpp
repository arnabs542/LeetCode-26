// Tags: Hash-table Amazon
// Time: O(n^2), where n = N (length of each list)
// Space: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // we don't want to avoid duplicates here, as we are asked number of ways
        unordered_map<int, int> ABSum;
        for (const auto& a : A) {
            for (const auto& b : B) {
                ++ABSum[a + b];
            }
        }
        int res = 0;
        for (const auto& c : C) {
            for (const auto& d : D) {
                if (ABSum.find(-(c + d)) != ABSum.end())
                    res += ABSum[-c-d];
            }
        }
        return res;
    }
};
/*
O(n^3) approach:
Same as 0018-4Sum

O(n^2) approach:
Take the arrays A and B, and compute all the possible sums of two elements.
Put the sum in the Hash map, and increase the hash map value if more than 
1 pair sums to the same value.

Compute all the possible sums of the arrays C and D. If the hash map contains
the opposite value of the current sum, increase the count of four elements sum 
by the counter in the map.

Note: We can't use this approach in 0018-4Sum, as there we don't have defined
separate boundaries (of possible values) for i, j, left and right pointers.
*/
