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
// Inorder Traversal
// Time O(n)
// Space O(h)
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> s {};
        double left_child_val = -numeric_limits<double>::max();

        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->val <= left_child_val)
                return false;
            left_child_val = root->val;
            root = root->right;
        }
        return true;
        }
    };

// Idea: Inorder Traversal gives sorted list of BST nodes
// Better Inorder Traversal in python 0230
