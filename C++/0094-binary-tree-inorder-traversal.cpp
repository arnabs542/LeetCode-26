// Time: O(n)
// Space: O(1)
// Morris inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                // find predecessor
                TreeNode *pred = cur->left;
                // keep going right till right node is not null or 
                // right node is not current.
                while (pred->right != cur && pred->right)
                    pred = pred->right;
                if (!pred->right) {
                    // (forward)
                    // go left after establishing link from predecessor
                    // to current.
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    // (backtrack)
                    // left is already visit. Go right after visiting current.
                    pred->right = nullptr;
                    nums.push_back(cur->val);
                    cur = cur->right;
                }
            } else {
                // visit and go to right
                nums.push_back(cur->val);
                cur = cur->right;
            }
        }
        return nums;
    }
};
