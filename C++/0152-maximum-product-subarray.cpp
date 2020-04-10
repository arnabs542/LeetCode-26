// Time O(n)
// Space O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int globalMax = numeric_limits<int>::min();
    int localMax = 1;
    int localMin = 1;
    int temp;

    for(const auto &n : nums)
    {
      temp = localMax;
      localMax = max({n,localMax*n,localMin*n});
      localMin = min({n,temp*n,localMin*n});
      globalMax = max(globalMax,localMax);

    }
    return globalMax;

    }
};
