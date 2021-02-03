// Tags: Amazon Hash-table Linked-list
// Time:  O(n)
// Space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> cloned;
        Node *cur = head;
        while (cur) {
            Node *ncur = new Node(cur->val);
            cloned[cur] = ncur;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            Node *ncur = cloned[cur];
            ncur->next = cloned[cur->next];
            if (cur->random)
                ncur->random = cloned[cur->random];
            cur = cur->next;
        }
        return cloned[head];
    }
};
