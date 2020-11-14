// Time:  O(n^2)
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
