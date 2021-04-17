// Tags: Tree DFS DP Amazon
// Time: O(n)
// Space: O(n), due to map
// Memoization solution
// Check Python version for comments
class Solution {
    unordered_map<TreeNode*, int> memo;
    // maximum amount that can be robbed from tree rooted at 'root'
    int dp(TreeNode* root) {
        if (!root)
            return 0;
        if (memo.count(root))
            return memo[root];
        int val = root->val;
        if (root->left)
            val += dp(root->left->left) + dp(root->left->right);
        if (root->right)
            val += dp(root->right->left) + dp(root->right->right);
        memo[root] = max(val, dp(root->left) + dp(root->right));
        return memo[root];
    }
public:
    int rob(TreeNode* root) {
        return dp(root);
    }
};
/*
dp[NULL] = 0;
dp[node] = max(node->val + sigma over (dp[g]), sigma over (dp[c]))
    where c denotes children of node and g denotes grandchildren of g
*/



// Time: O(n)
// Space: O(1) w/o stack, O(h) w/ stack
// Greedy solution
// Check Python version for comments
class Solution {
    // maximum amount of money that can be robbed from tree rooted at 'root'
    // if 'root' is not robbed, if 'root' is robbed
    vector<int> robSum(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto left = robSum(root->left);
        auto right = robSum(root->right);
        // Note that a is not left[1] + right[1]
        // if root is not robbed, children may or may not be robbed
        // or may be just one of them is robbed
        int a = max(left[0], left[1]) + max(right[0], right[1]);
        // if root is robbed, children can't be robbed
        int b = root->val + left[0] + right[0];
        return {a, b};
    }
public:
    int rob(TreeNode* root) {
        auto res = robSum(root);
        return max(res[0], res[1]);
    }
};
// No longer have repeated subproblems
