// Tags: Tree Amazon
// Time: O(n)
// Space: O(h)
// Postorder traversal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // last right could also be nullptr (Case 3)
        return left ? (right ? root : left) : right;
        // or if (left && right)
        //     return root;
        // return left ? left : right;
    }
};
/*
Think of a node in each call as a subtree rooted at
that node.

There are three cases:
1. If the current (sub)tree contains both p and q then return
   current node. 

2. If only one of them is in that subtree, then return that node.
   (helps sending the resultant node back to the root)

3. If neither are in that subtree, the return nullptr.
*/



// Time: O(n)
// Space: O(h)
// Iterative postorder traversal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        vector<TreeNode*> st, pathP, pathQ;
        while (cur || !st.empty()) {
            if (cur) {
                st.push_back(cur);
                // check and set path for p
                if (st.back() == p)
                    pathP = st;
                // check and set path for q
                if (st.back() == q)
                    pathQ = st;
                cur = cur->left;
            } else {
                // st.top()->left is nullptr
                cur = st.back()->right;
                if (!cur) {
                    // st.top()->right is nullptr
                    TreeNode* last = nullptr;
                    // keep visiting right children
                    while (!st.empty() && last == st.back()->right) {
                        last = st.back(); st.pop_back();
                        // visit last
                    }
                }
            }
        }
        // compare paths (starting from root) and get lowest common ancestor
        int n = min(pathP.size(), pathQ.size());
        for (int i = 0; i < n; ++i) {
            // first mismatch
            if (pathP[i] != pathQ[i])
                return pathP[i - 1];
        }
        // if lca is either one of p and q
        return pathP[n - 1];
    }
};
/*
Unlike preorder traversal using stack, in postorder whenever we reach a target
node, stack at that point contains only the nodes along the path that leads to
that.
*/
