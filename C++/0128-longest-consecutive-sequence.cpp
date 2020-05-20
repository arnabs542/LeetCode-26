// Time O(n)
// Space O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        unordered_map<int,int> hash;
        int ans{1};
        for (const auto &n: nums) {
            if (!hash[n]) {
                hash[n] = 1;
                int leftbound {hash[n-1]}, rightbound {hash[n+1]};
                hash[n - leftbound] = hash [n + rightbound] = 1 + leftbound + rightbound;
                ans = max(ans, 1 + leftbound + rightbound);
            }
        }
        return ans;
    }
};
