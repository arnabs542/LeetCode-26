// Tags: Tree DFS Amazon
// Time: O(n)
// Space: O(h), h is the height of the binary tree.
// Recursive solution
class Solution {
    // left and right are the roots of the subtrees
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        return left->val == right->val &&
            isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }
};
/*
Two trees are a mirror reflection of each other if:
1. Their two roots have the same value.
2. The right subtree of each tree is a mirror reflection
of the left subtree of the other tree.
*/



// Time: O(n)
// Space: O(h), h is the height of the binary tree.
// Iterative solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        stack<TreeNode*> st;
        // isSymmetricHelper(root->left, root->right)
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            // right is popped first by property of stack
            auto right = st.top(); st.pop();
            auto left = st.top(); st.pop();
            if (!left && !right)
                continue;
            if (!left || !right || left->val != right->val)
                return false;
            
            // isSymmetricHelper(left->left, right->right)
            st.push(left->left);
            st.push(right->right);
            
            // isSymmetricHelper(left->right, right->left)
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }
};
/*
Push and pop each pair of left and right nodes together.
*/
