// Tags: Tree Amazon Premium
// Time:  O(n)
// Space: O(h)
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root)
            return {};
        vector<int> nodes {root->val};
        if (root->left) {
            leftBoundary(root->left, nodes);
            leaves(root->left, nodes);
        }
        if (root->right) {
            leaves(root->right, nodes);
            rightBoundary(root->right, nodes);
        }
        return nodes;
    }
    // preorder
    void leftBoundary(TreeNode* root, vector<int> &nodes) {
        // skip putting leftmost node in the result
        if (!root->left && !root->right)
            return;
        nodes.push_back(root->val);
        if (root->left)
            leftBoundary(root->left, nodes);
        else if (root->right)
            leftBoundary(root->right, nodes);
    }
    // preorder
    void leaves(TreeNode* root, vector<int> &nodes) {
        // push all leaf nodes
        if (!root->left && !root->right) {
            nodes.push_back(root->val);
            return;
        }
        if (root->left)
            leaves(root->left, nodes);
        if (root->right)
            leaves(root->right, nodes);
    }
    // postorder
    void rightBoundary(TreeNode* root, vector<int> &nodes) {
        // skip putting rightmost node into the result
        if (!root->left && !root->right)
            return;

        if (root->right)
            rightBoundary(root->right, nodes);
        else if (root->left)
            rightBoundary(root->left, nodes);

        // push in the reverse order (while returning)
        nodes.push_back(root->val);
    }
    
};

/*
We don't need to take union of three lists as in all
cases only 2 nodes (leftmost and rightmost) overlap with
the leaves (which we can easily skip in leftBoundary & rightBoundary
functions)
*/
