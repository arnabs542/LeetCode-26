// Tags: WC230 Backtracking
// Time: O(n*(3^m))
// Space: O(3^m)
// Optimized
class Solution {
    void helper(vector<int>&toppingCosts, int target, int i, int cur, int &res) {
        // record result after each index i
        if (abs(target - cur) < abs(target - res) ||
                (abs(target - cur) == abs(target - res) && cur < res)) {
                res = cur;
        }
        // no more toppings to add or
        // if cur is greater than or equal to target, we do not need to check further
        // as adding current topping to it will further increase the difference.
        if (i == toppingCosts.size() || cur >= target) {
            return;
        }
        for (int j = 0; j <= 2; ++j) {
            helper(toppingCosts, target, i + 1, cur + j*toppingCosts[i], res);
        }
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = baseCosts[0];
        for (int base_cost : baseCosts) {
            helper(toppingCosts, target, 0, base_cost, res);
        }
        return res;
    }
};



class Solution {
    // int min_diff = INT_MAX;
    void dfs(vector<int>&toppingCosts, int target, int i, int cur, int &res) {
        if (i == toppingCosts.size()) {
            if (abs(target - cur) < abs(target - res) ||
                (abs(target - cur) == abs(target - res) && cur < res)) {
                res = cur;
                //min_diff = abs(target - cur);
            }
            return;
        }
        for (int j = 0; j <= 2; ++j) {
            dfs(toppingCosts, target, i + 1, cur + j*toppingCosts[i], res);
        }
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = baseCosts[0];
        for (int base_cost : baseCosts) {
            dfs(toppingCosts, target, 0, base_cost, res);
        }
        return res;
    }
};
