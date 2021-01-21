// Tags: Amazon Tree DFS
// Time:  O(n)
// Space: O(h), h is height of binary tree
class Solution {
public:
    int maxSum = numeric_limits<int>::min();
    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return maxSum;
    }
// PathSum() returns the maximum gain one could have including the node and may
// be one of its subtrees into the path
    int PathSum (TreeNode* node){
        if (node == nullptr)
            return 0;
        // if any branch returns negative path sum, we can skip that branch
        int left = max(0, PathSum(node->left));
        int right = max(0, PathSum(node->right));

        maxSum = max(maxSum, left + right + node->val);

        return max(left,right) + node->val;

    }
};
