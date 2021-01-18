// Tags: Tree Recursion DFS Amazon
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

/* Idea: Inorder Traversal gives sorted list of BST nodes */



// Iterative Inorder, Better
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long left_child_val = numeric_limits<long>::min();;
        TreeNode* cur = root;
        while (!st.empty() or cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                if (cur->val <= left_child_val)
                    return false;
                left_child_val = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};
/*
  At each step we check if the current node's value is
  greater than the right most node of the left subtree. 
*/



// Time: O(n)
// Space: O(logn)
// Recursive Preorder
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
    // at each node we check if root-val is within limits
    bool helper(TreeNode* root, long low, long high) {
        if (!root)
            return true;
        // for left subtree, root->val is the upper limit
        // and for right subtree, root->val is the lower limit
        return low < root->val && root->val < high &&
            helper(root->left, low, root->val) &&
            helper(root->right, root->val, high);
    }
};
