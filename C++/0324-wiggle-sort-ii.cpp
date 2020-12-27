// Tags: Sort Top-interview
// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(1)
// Virtual indexing with Three-way partition
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // find median
        // nth_element takes O(n) average time
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int mid = *it;
        
        // index rewiring
        #define A(i) nums[(2*i + 1) % (n|1)]
        
        // 3-way-partition-to-wiggly in O(n) time with O(1) space
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)    // j not incremented so we check
                swap(A(k--), A(j)); // again if new A(j) > mid
            else
                ++j;
        }
    }
};


/*
For example: 
index:     0  1  2  3   4   5  6  7  8  9
number:   18 17 19 16  15  11 14 10 13 12

In dutch national flag problem, 
    i -> keeps track of the latest index to swap with on left 
    (for elem < mid)
    k -> keeps track of the latest index to swap with on right 
    (for elem > mid)

In wiggle sort, median becomes mid
and we are rewiring indices such what
    i -> accesses all odd locations
    & k -> accesses all even locations
Now, the three-way partitioning automatically arranges the numbers in
the wiggle sort pattern. (also we switched roles of i & k in the original
partitioning algorithm)

* arranging numbers > median
Accessing A(0) actually accesses nums[1].
Accessing A(1) actually accesses nums[3].
Accessing A(2) actually accesses nums[5].
Accessing A(3) actually accesses nums[7].
Accessing A(4) actually accesses nums[9].

* arranging numbers < median
Accessing A(5) actually accesses nums[0].
Accessing A(6) actually accesses nums[2].
Accessing A(7) actually accesses nums[4].
Accessing A(8) actually accesses nums[6].
Accessing A(9) actually accesses nums[8]
*/
