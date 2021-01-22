// Tags: Sort Amazon
// Time:  O(nlogn)
// Space: O(1)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort numbers
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            // if this condition returns true, a will come on the left of b in
            // the sorted list
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        }); 
        string res;
        // combine the numbers
        for (const auto &n: nums)
            res.append(to_string(n));
        
        // special case: start with zero (e.g. [0, 0])
        if (!res.empty() && res[0] == '0')
            return "0";
        
        return res;
    }
};
/*
Simply sorting the numbers converted into strings in decreasing order
will not work. 
Take the following case:
    [3,30,34,5,9]
If we do so, Output would be
    "9534303"
but the Expected is
    "9534330"
*/
