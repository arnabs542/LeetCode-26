// Tags: Tree Recursion
// Time:  O(n * 4^n / n^(3/2)) ~= n*Catalan number
// Space: O(n * 4^n / n^(3/2)), not sure
// Based on 0096-unique-binary-search-trees
class Solution {
    TreeNode* clone(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);
        return new_root;
    }
    vector<TreeNode*> helper(int i, int j) {
        if (i > j)
            return {nullptr};
        vector<TreeNode*> cur_list;
        for (int r = i; r <= j; ++r) {
            vector<TreeNode*> left_subtrees = helper(i, r - 1);
            vector<TreeNode*> right_subtrees = helper(r + 1, j);
            for (auto& left : left_subtrees) {
                for (auto& right : right_subtrees) {
                    // take unique root at each iteration
                    TreeNode *root = new TreeNode(r);
                    // unique left subtree
                    root->left = clone(left);
                    // unique right subtree
                    root->right = clone(right);
                    cur_list.push_back(root);
                }
            }
        }
        return cur_list;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return helper(1, n);
    }
};
