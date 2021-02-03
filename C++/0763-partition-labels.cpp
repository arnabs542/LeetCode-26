// Tags: Amazon Sliding-window Greedy
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> lookup;
        // last indices of each char
        for (int i = 0; i < S.length(); ++i) {
            lookup[S[i]] = i;
        }
        int first = 0, last = 0;
        vector<int> res;
        for (int i = 0; i < S.length(); ++i) {
            last = max(last, lookup[S[i]]);
            // last index is current index
            if (i == last) {
                res.push_back(i - first + 1);
                first = i + 1;
            }
        }
        return res;
    }
};
