// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
       if (nums.size() == 0)
           return 0;
        if (nums.size() == 1)
            return nums[0];

        return max(robRange(nums, 0, nums.size() - 2),
                    robRange(nums, 1, nums.size() - 1));
    }

    int robRange(vector<int> &nums, int start, int end)
    {
        int last = 0, result = 0;
        int tmp;
        for (int i = start; i <= end; ++i) {
            tmp = result;
            result = max(result, last + nums[i]);
            last = tmp;
        }
        return result;
    }
};
