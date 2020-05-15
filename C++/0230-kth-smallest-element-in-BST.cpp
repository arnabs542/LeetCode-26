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


// Time:  O(max(h, k))
// Space: O(min(h, k))
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        deque<TreeNode *> s;
        TreeNode *cur = root;
        int rank = 0;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace_back(cur);
                if (s.size() > k)
                    s.pop_front();
                cur = cur->left;
            } else {
                cur = s.back();
                s.pop_back();
                if (++rank == k)
                    return cur->val;
                cur = cur->right;
            }
        }

        return INT_MIN;
    }
};

/* Using deque instead of stack saves space
 * Deque behaves like max heap
 */
