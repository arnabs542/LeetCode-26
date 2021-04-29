// Tags: WC235 Math
// Time: O(n*sqrt(m)*(logm+logm)), n = len(nums), m = max(nums) (max element in nums)
// Space: O(200001) ~ O(1)
class Solution {
    int gcd(int a, int b) {
        int temp;
        while (b > 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        // using an array as a hash table
        // index = factor, value = gcd of a subsequence of numbers having this factor
        int fac_to_gcd[200001] = {};
        for (int i = 0; i < nums.size(); ++i) {
            // find all factors of nums[i]
            for (int f = 1; f * f <= nums[i]; ++f) {
                if (nums[i] % f == 0) {
                    fac_to_gcd[f] = gcd(fac_to_gcd[f], nums[i]);
                    fac_to_gcd[nums[i] / f] = gcd(fac_to_gcd[nums[i] / f], nums[i]);
                }
            }
        }
        // count of unique gcd's
        int cnt = 0;
        for (int i = 1; i <= 200000; ++i)
            if (fac_to_gcd[i] == i) {
                // factor i is the highest common factor of the subsequence
                ++cnt;
            }
        return cnt;
    }
};
/*
So, the intuition here is that, instead of forming all sorts of groups, we can check
whether each number in range [1...200,000] can be GCD for any subsequence of numbers in our
array.

In order to check if we could form some number i as GCD, we first find out all numbers that
have a factor of i in them.
Now in order for some subsequence of them to form i as GCD, it must be true that these numbers
(with factor of i in them) must all have a combined GCD of i as well.

As a subsequence can have multiple common factors, if numbers with factor of i in them form a
GCD > i, then we can never form i with any subsequence of them.
*/
