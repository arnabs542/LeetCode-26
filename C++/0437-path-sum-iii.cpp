// Time: O(n)
// Space: O(n)
// Check Python version for comments
class Solution {
    unordered_map<int, int> sum_count;
    int result = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        // like base case in dp
        sum_count[0] = 1;
        dfs(root, sum, 0);
        return result;
    }
    
    void dfs(TreeNode* root, int target, int rsum) {
        if (!root)
            return;
        rsum += root->val;
        if (sum_count.count(rsum - target)) {
            result += sum_count[rsum - target];
        }

        sum_count[rsum] += 1;

        dfs(root->left, target, rsum);
        dfs(root->right, target, rsum);
        
        sum_count[rsum] -= 1;
    }
};
