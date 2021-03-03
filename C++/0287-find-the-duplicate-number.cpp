// Tags: Array Two-pointers Binary-search Amazon
// Time: O(n)
// Space: O(1)
// Floyd's tortoise and hare (cycle detection)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Treat each (index, value) pair of the array as
        // (pointer, next) node thus duplicated number will
        // be the begin of the cycle in linked list

        // find the collision point of the two runners
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // find the entrance to the cycle
        slow = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
/*
First of all, where does the cycle come from?
Let's use the function f(x) = nums[x] to construct the sequence:
x, nums[x], nums[nums[x]], nums[nums[nums[x]]], ....

Each new element in the sequence is an element in nums at the index 
of the previous element.

If one starts from x = nums[0], such a sequence will produce a linked
list with a cycle.

index 0 1 2 3 4 5 6
nums  2 6 4 1 3 1 5

start: x = nums[0] = 2

2 -> 4 -> 3 -> 1 -> 6 -> 5
               ^         |
               |_________|
The cycle appears because nums contains duplicates. 
The duplicate node is a cycle entrance.
(Check description in CTCI)
*/



// Time: O(nlogn), search logn times
// Space: O(1)
// Binary search method (search space)
// Check Python version for comments
// Not recommended, simply sorting and check checking nums[i] == nums[i - 1]
// is also done in O(nlogn) time & O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int count = 0;
            for (auto n: nums)
                if (n <= mid)
                    ++count;
            if (count > mid) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
