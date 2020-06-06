// Time:  create prefix_sum: O(n)
//        pickIndex: O(logn)
// Space: O(n)
class Solution {
private:
    vector<int> prefix_sum;
public:
    Solution(vector<int>& w) {

    for (int weight: w) {
        if (prefix_sum.empty())
            prefix_sum.push_back(weight);
        else
            prefix_sum.push_back(prefix_sum.back() + weight);
    }

    }

    int pickIndex() {
        int x = prefix_sum.back();
        int random_num = rand() % x;
        auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), random_num);
        return it - prefix_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
 /*
 Notes:
 upper_bound - Returns an iterator pointing to the first element
              in the range [first,last) which compares
              greater than val.
lower_bound - ......does not compare less than val
*/
