// Tags: Amazon Tree Premium
// Time: O(n)
// Space: O(h), where h = height of the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double result;
        postorder(root, result);
        return result;
    }
    
    pair<int, int> postorder(TreeNode* root, double &result) {
        if (!root)
            return {0, 0};
        auto [n1, s1] = postorder(root->left, result);
        auto [n2, s2] = postorder(root->right, result);
        result = max(result, (s1 + s2 + root->val)/(n1 + n2 + 1.0));
        return {n1 + n2 + 1, s1 + s2 + root->val};
    }
};
