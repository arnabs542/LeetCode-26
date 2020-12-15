// Tags: Amazon Array
// Time O(n)
// Space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      if(nums.empty())
      return {};

      vector<int> leftProduct(nums.size());

      leftProduct[0] = 1;

      for(int i=1; i<nums.size(); ++i)
      leftProduct[i] = leftProduct[i-1]*nums[i-1];

      int rightProduct = 1;

      for(int i = nums.size()-2; i>=0 ; --i)
      {
        rightProduct*=nums[i+1];
        leftProduct[i]*=rightProduct;
      }

      return leftProduct;

    }
};
