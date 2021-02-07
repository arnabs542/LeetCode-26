// Tags: Amazon DFS Tree
// Time: O(n)
// Space: O(n)
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        getParents(root);
        dfs(target, K, res);
        return res;
    }

    void dfs(TreeNode* root, int K, vector<int> &res) {
        // prevent going back (close to target)
        if (visited.count(root))
            return;
        visited.insert(root);
        if (K == 0) {
            res.push_back(root->val);
            return;
        }
        if (root->left)
            dfs(root->left, K - 1, res);
        if (root->right)
            dfs(root->right, K - 1, res);
        if (parent.count(root))
            dfs(parent[root], K - 1, res);
    }

    void getParents(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            parent[root->left] = root;
            getParents(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            getParents(root->right);
        }
    }
};

// To do: solution without hashmap
