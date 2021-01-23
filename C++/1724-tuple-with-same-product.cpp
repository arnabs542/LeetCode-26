// Tags: Array Hash-table WC224
// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCnt;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // (if this is the first time this product is seen,
                // res is not incremented)
                /// Every tuple has 8 permutations //
                res += 8*productCnt[nums[i]*nums[j]];
                ++productCnt[nums[i]*nums[j]];
            }
        }
        return res;
    }
};

/*
We count the product of every 2 distinct numbers rather than count 
each individual number, then it's easy to solve.
*/

/*
From test case 1 [2,3,4,6] we have count map which is 
{6:1, 8:1, 12:2, 18:1 , 24:1}, 12:2 makes res += 8 and
from test case 3 [2,3,4,6,8,12] we know that when we loop to 8,
we have additional products 8*2, 8*3, 8*4, 8*6 = 16, 24, 32, 48
to add to count map, then our count map becomes 
{6:1, 8:1, 12:2, 16:1, 18:1, 24:2, 32:1, 48:1}, 24:2 makes res += 8
*/
