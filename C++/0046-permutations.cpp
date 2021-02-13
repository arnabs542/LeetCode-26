// Tags: Backtracking Amazon
// Time: O(n * n!), if n choices for 1st element, n - 1 choices for 2nd element.
// (n * (n - 1) nodes in the 2nd level), n - 2 choices for 3rd element, (n * (n - 1)*(n -2)
// nodes in the 3rd level)......1 choice for nth element (n! nodes in the nth level)
// So in worst case, we have O(n*n!) total nodes in our decision tree. 
// Space: O(n)
class Solution {
    void dfs(vector<int> &nums, vector<bool> &added, vector<vector<int>> &res, vector<int> &cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (added[i])
                continue;
            added[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, added, res, cur);
            cur.pop_back();
            added[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // index to bool
        vector<bool> added(nums.size());
        vector<int> cur;
        dfs(nums, added, res, cur);
        return res;
    }
};

/*
Instead of using an added & cur array, we can swap elements
in the nums array before calling recursive function
swap(num[begin], num[i]);

and then swap back to original configuration.
swap(num[begin], num[i]);

where begin is current index to be filled 0 <= begin < nums.size()
*/
