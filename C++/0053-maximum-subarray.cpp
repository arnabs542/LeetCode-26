// Time O(n)
// Space O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

      int result= numeric_limits<int>::min();
      int opt = numeric_limits<int>::min();

      for (const auto &n : nums)
      {
        opt = (opt==numeric_limits<int>::min()) ? n : max(opt+n,n);
        result = max(result,opt);
      }

      return result;
    }
};
