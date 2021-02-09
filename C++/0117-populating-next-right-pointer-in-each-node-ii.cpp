// Tags: Amazon Tree DFS
// Time: O(n)
// Space: O(1)
// Iterative level order
class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        // first node of the next level
        Node dummy;
        Node* last = &dummy;
        // head is the first node of a level
        while (head) {
            Node* cur = head;
            // iterate on the current level & set next pointers to children
            while (cur) {
                if (cur->left) {
                    last->next = cur->left;
                    last = last->next;
                }
                if (cur->right) {
                    last->next = cur->right;
                    last = last->next;
                }
                // move to the next sibling
                cur = cur->next;
            }
            // move to the next level
            head = dummy.next;
            // reset the last pointer
            dummy.next = nullptr;
            last = &dummy;
        }
        return root;
    }
};

/*
Unlike 0116-populating-next-right-pointers-in-each-node,
any node can have just one child, so we cant use 

1. while (cur && cur->left) to iterate over current level
2. head = head->left to move to next level
(3. if (cur->next)
        cur->right = cur->next->left)

That's why here we keep track of the last child in the current
level using a pointer 'last'.

Instead of thinking what nodes children should point to?
think about what other nodes should point to these children?
*/
