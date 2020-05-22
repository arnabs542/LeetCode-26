// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
      int res = nums.size();
      for (int i = 0; i < nums.size(); i++) {
        res ^= i;
        res ^= nums[i];
      }
      return res;
    }
};



/* Notes:
Idea - a^b^b = a
In complete array with no missing numbers, nums[i]=i
Therefore, we apply XOR to both index and value
assuming missing number is at index = nums.size()
then one of the index will give missing number.
*/
