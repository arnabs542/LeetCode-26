// Tags: Bit-manipulation Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for (int num: nums) {
            // if num not in seen_twice, 
            //    either add it to seen_once (first occurence) 
            //    or remove it (second occurence)
            seen_once = ~seen_twice & (seen_once ^ num);
            // if num not in seen_once,
            //    either add it to seen_twice (second occurence)
            //    or remove it (third occurence)
            seen_twice = ~seen_once & (seen_twice ^ num);
        }
        return seen_once;
    }
};
/*
Intuition:
Let's start from XOR operator which could be used to detect the bit which appears
odd number of times: 1, 3, 5, etc.
0 ^ x = x first occurence
x ^ x = 0 second occurence
0 ^ x = x third occurence
So one could detect the bit which appears once, and the bit which appears three times.
The problem is to distinguish between these two situations.

To separate number that appears once from a number that appears three times
let's use two bitmasks / sets instead of one: seen_once and seen_twice.

Assume "seen_once" and "seen_twice" to be sets that are keeping track of which numbers have
appeared once and twice respectively;

First of all, consider the (set^val) as one of the following:
1. adding "val" to the "set" if "val" is not in the "set" => A^0 = A
2. removing "val" from the "set" if "val" is already in the "set" => A^A = 0

How it works?:
Effectively,
1. Any number that appears a first time will be in set "seen_once" so it will not be
   added to "seen_twice".

2. Any number appearing a second time would have been removed from set
   "seen_once" in the previous step and will now be added to set "seen_twice".

3. Lastly, any number appearing a third time will simply be removed from the set "seen_twice" and
   will no longer exist in either set.

Finally, once we are done iterating over the entire list, set "seen_twice" would be empty and
set "seen_once" will contain the only number that appears once.
*/
