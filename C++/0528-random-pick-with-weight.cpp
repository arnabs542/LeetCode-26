// Tags: Binary-search Random Google
// Time: create prefix_sum: O(n)
//       pickIndex: O(logn)
// Space: O(n)
class Solution {
    vector<int> prefix_sum;
public:
    Solution(vector<int>& w) {
        // prefix_sum[i] = prefix_sum[i - 1] + w[i]
        partial_sum(w.begin(), w.end(), back_inserter(prefix_sum), plus<int>());
    }
    
    int pickIndex() {
        // + 1 as we want to get a value in the [1, prefix_sum.back()]
        // instead of [0, prefix_sum.back() - 1]
        int idx = rand() % prefix_sum.back() + 1;
        // search for first number >= idx
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), idx);
        // or upper_bound(prefix_sum.begin(), prefix_sum.end(), rand() % prefix_sum.back());
        return it - prefix_sum.begin();
    }
};
/*
Instead of having an array with w[i] instances of any index i, we can create a prefix sum
array and later perform a binary search to pick and index, maintaing the probabilities.
*/



// Brute force, time limit exceeded and also takes too much memory
// Time: O(w[i]*w.length) for constructor, O(1) for pickIndex()
// Space: O(w[i]*w.length)
class Solution {
    vector<int> s;
public:
    Solution(vector<int>& w) {
        int i = 0;
        for (int x : w) {
            int t = 0;
            while (t < x) {
                s.push_back(i);
                ++t;
            }
            ++i;
        }
    }
    
    int pickIndex() {
        return s[rand() % s.size()];
    }
};
/*
The brute force approach is to have as many instances of i as w[i] in order to get
the required probability when indexing the resultant array with a random number.
*/
