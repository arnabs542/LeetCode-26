// Tags: Tree Amazon Premium
// Time: O(h), where in a balanced bst h = logn
// (in worst case h could be as large as n)
// Space: O(h)
// Recursive solution (postorder traversal),
// hard to understand
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return nullptr;
        // search in the right subtree
        if (p->val >= root->val)
            return inorderSuccessor(root->right, p);
        else {
            // p-val < root->val
            // if we couldn't find it in the left subtree (returns nullptr),
            // then successor is the current root
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

/*
First we go to exact path (right subtree) of node till end for which we want
to find out inorder successor using BST property.

Use back track, Consideration for every node while back track
(a). For every node if we backtrack from right side then simply
     return because successor will be its parent.
(b). If we backtrack from left side, then successor will be 
     Either current node OR any successor found in left subtree.
*/



// Time: O(h)
// Space: O(1)
// Iterative solution, easier to understand
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // if it has right subtree
        if (p->right) {
            p = p->right;
            // find left most node of right subtree
            while (p->left)
                p = p->left;
            return p;
        }
        // otherwise do a regular search from root to p but
        // remember the node of the last left-turn and return that.
        TreeNode* successor = nullptr;
        while (root != p) {
            if (p->val < root->val) {
                // left turn
                successor = root;
                root = root->left;
            } else {
                // p->val > root->val
                root = root->right;
            }
        }
        return successor;
    }
};
