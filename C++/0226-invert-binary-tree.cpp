// Time O(n)
// Space o(h)
// DFS Recursive solution
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr){
            swap (root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

// Time O(n)
// Space o(h)
// DFS Iterative Stack Solution
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr){
            stack<TreeNode*> nodes;
            nodes.push(root);
            //nodes.emplace(root);

            while (!nodes.empty()){
                auto node = nodes.top();
                nodes.pop();
                swap(node->left, node->right);
                // instead of print in dfs

                if (node->left != nullptr){
                    nodes.push(node->left);
                    //.emplace
                }

                if (node->right != nullptr){
                    nodes.push(node->right);
                    //.emplace
                }


            }
        }
        return root;

    }
};




// Time O(n)
// Space O(w), w is max number of nodes at a level
// BFS Iterative Queue Solution
class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr){
            queue<TreeNode*> nodes;
            nodes.push(root);
            //nodes.emplace(root);

            while (!nodes.empty()){
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                // instead of print in bfs

                if (node->left != nullptr){
                    nodes.push(node->left);
                    //.emplace
                }

                if (node->right != nullptr){
                    nodes.push(node->right);
                    //.emplace
                }


            }
        }
        return root;

    }
};
