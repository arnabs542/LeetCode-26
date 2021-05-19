// Tags: Tree Google
// Time: O(n)
// Space: O(h)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        
        if (!root1 || !root2 || root1->val != root2->val)
            return false;
        
        // without swapping
        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
        // with swapping
            flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};
/*
We just need to see which node of Tree X should be paired with which node of Tree Y, so that
they can be checked if their values match.
*/



// Time: O(n)
// Space: O(n), max nodes at any level
// Bfs
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q1({root1}), q2({root2});
        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;
            if (!node1->left && !node2->left || (node1->left && node2->left && node1->left->val == node2->left->val)) {
                // without swapping
                q1.push(node1->left);
                q1.push(node1->right);
            } else {
                // with swapping (order reversed)
                q1.push(node1->right);
                q1.push(node1->left);
            }
            q2.push(node2->left);
            q2.push(node2->right);
        }
        return true;
    }
};
/*
In iterative versions we cannot try both pairing options blindly, 
we have to select one between the two.
*/



// Time: O(n)
// Space: O(h)
// Iterative Dfs (Same as Bfs)
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1({root1}), st2({root2});
        while (!st1.empty() && !st2.empty()) {
            auto node1 = st1.top(); st1.pop();
            auto node2 = st2.top(); st2.pop();
            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;
            if (!node1->left && !node2->left || (node1->left && node2->left && node1->left->val == node2->left->val)) {
                // without swapping
                st1.push(node1->left);
                st1.push(node1->right);
            } else {
                // with swapping (order reversed)
                st1.push(node1->right);
                st1.push(node1->left);
            }
            st2.push(node2->left);
            st2.push(node2->right);
        }
        return true;
    }
};
