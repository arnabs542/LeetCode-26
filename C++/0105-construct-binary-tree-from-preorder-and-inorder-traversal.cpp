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

// Time O(n^2)
// Space O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }
    TreeNode *helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return nullptr;

        auto root = new TreeNode(preorder[preStart]);
        int inIndex = 0;

        for (int i = inStart; i <= inEnd; i++) {
            if (root->val == inorder[i])
                inIndex = i;
        }

        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        // get the immediate right child index by
        // skipping all the nodes on the left branches/subtrees of current node.
        return root;
    }
};


// Improvement to use hashmap to cache inorder[] positions.
// Time O(n)
// Space O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> lookup;

        for (int i=0; i < inorder.size(); i++) {
            lookup.emplace(inorder[i], i);
            //.insert(make_pair(inorder[i], i))
            // lookup[inorder[i]] = i
        }
        return helper(0, 0, inorder.size() - 1, preorder, inorder, lookup);
    }
    TreeNode *helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder, const unordered_map<int, int> &lookup) {
        // first condition is not required
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return nullptr;

        auto root = new TreeNode(preorder[preStart]);
        int inIndex = lookup.at(root->val);
        // = lookup[root->val]

        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder, lookup);
        root->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder, lookup);
        // get the immediate right child index by
        // skipping all the nodes on the left branches/subtrees of current node.
        return root;
    }
};


/* Notes:
Traversing unordered_map<int,int> m;
for (const auto &p : m) {
        std::cout << p.first << " => " << p.second << '\n';
    }
OR
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << "  " << itr->second << endl;
     }
*/
