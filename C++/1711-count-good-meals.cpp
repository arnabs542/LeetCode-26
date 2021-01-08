// Tags: Hash-table Array
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto &n: deliciousness) {
            for (int i = 0; i < 22; ++i) {
                int tmp = (1 << i) - n;
                if (cnt.count(tmp))
                    res = (res + cnt[tmp]) % 1000000007;
            }
            ++cnt[n];
        }
        return res;
    }
};

/*
we can further reduce the constant modifier to 22 from 32, 
due to the constraint in problem that 0 <= deliciousness[i] <= 2^20
*/
