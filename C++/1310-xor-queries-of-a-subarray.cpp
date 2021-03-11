// Tags: Bit-manipulation Amazon
// Time: O(n)
// Space: O(q)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        // prefix[i] = arr[0].....arr[i]
        for (int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i - 1];
        for (auto q : queries) {
            res.push_back(q[0] > 0 ? arr[q[0] - 1] ^ arr[q[1]] : arr[q[1]]);
        }
        return res;
    }
};
/*
In-place calculate the prefix XOR of input A.

For each query [i, j],
if i == 0, query result = A[j]
if i != 0, query result = A[i - 1] ^ A[j]
*/
