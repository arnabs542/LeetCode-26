// Tags: Amazon Tree BFS
// Time:  O(n)
// Space: O(n)
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> cur {root};
        vector<vector<int>> res;
        if (!root)
            return res;
        while (!cur.empty()) {
            vector<int> vals;
            vector<TreeNode*> next;
            for (auto &node: cur) {
                vals.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }
            cur = next;
            if (res.size() % 2 != 0)
                reverse(vals.begin(), vals.end());
            res.push_back(vals);
        }
        return res;
    }
};
