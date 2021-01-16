// Tags: Tree DFS BFS
// Time: O(n)
// Space: O(n)
// Level order traversal using queue (Bfs)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                Node* node = q.front(); q.pop();
                node->next = i == sz - 1 ? nullptr : q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};



// Time: O(n)
// Space: O(logn), due to recursion stack
// Recursive preorder tree traversal (Dfs)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left)
            return root;
        if (root->left)
            root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};



// Time: O(n)
// Space: O(1)
// Iterative level order traversal
class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        // head is the first node of a level
        while (head) {
            Node* cur = head;
            // iterate on the current level & set next pointers of children
            // (only valid until the second last level)
            while (cur && cur->left) {
                // add link between left and right childs
                if (cur->left)
                    cur->left->next = cur->right;
                // add link between right child and left child
                // of right sibling
                if (cur->next)
                    cur->right->next = cur->next->left;
                // move to right sibling
                cur = cur->next;
            }
            // move to next level
            head = head->left;
        }
        return root;
    }
};
