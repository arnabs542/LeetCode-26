// Tags: DP Array Greedy Amazon
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool *dp = new bool[nums.size()] {false};
        dp[0] = true;

        for (int i = 1; i < nums.size(); i++)
            for (int j = i-1; j >= 0; j--)
            {
                if (nums[j] >= i - j && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        return dp[nums.size()-1];

    }
};
/*
opt[i] denotes if we can reach the last element in the
array 0,.....,i
*/



// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodIdx = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] >= lastGoodIdx - i)
                lastGoodIdx = i;
        }
        return lastGoodIdx == 0;
    }
};

/*
As expected Greedy solution takes less time than DP solution.
lastGoodIdx = index from where we can reach the end.

Greedy Choice property: take the last good index position and see if it is
reachable.

Optimal substructure: at each iteration, we've a local optimal
solution to our subproblem.

If we went from left to right, for each index, we might have to
check every index before it.
But since we go from right to left, we only interate the list once.
*/
