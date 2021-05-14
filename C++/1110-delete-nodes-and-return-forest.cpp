// Tags: Tree DFS Google
// Time: O(n)
// Space: O(h + d), d is the number of to_delete
// Postorder traversal
class Solution {
    TreeNode* helper(TreeNode* root, unordered_set<int> &to_delete, vector<TreeNode*>& res) {
        if (!root)
            return nullptr;
        root->left = helper(root->left, to_delete, res);
        root->right = helper(root->right, to_delete, res);
        if (to_delete.count(root->val)) {
            if (root->left)
                res.push_back(root->left);
            if (root->right)
                res.push_back(root->right);
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        root = helper(root, to_del, res);
        if (root)
            res.push_back(root);
        return res;
    }
};
