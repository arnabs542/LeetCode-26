// Tags: Array Amazon
// Time O(n)
// Space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        for (auto x : nums) {
            if (!numSet.count(x - 1)) {
                int y = x + 1;
                while (numSet.count(y))
                    ++y;
                best = max(best, y - x);
            }
        }
        return best;
    }
};
/*
Then go through the numbers. 

If the number x is the start of a streak (i.e., x-1 is not in the set),
then test y = x+1, x+2, x+3, ... and stop at the first number y not in
the set. The length of the streak is then simply y-x and we update our
global best with that.

Since we check each streak only once, this is overall O(n)
*/



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
