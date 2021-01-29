// Tags: Linked-list Amazon
// Time: O(n)
// Space: O(1)
// Reusing idea of 0025-reverse-nodes-in-k-group
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // beg is left boundary node
        // dummy is required as m could be 1
        ListNode dummy;
        dummy.next = head;
        ListNode *beg = &dummy;
        for (int i = 0; i < m - 1; ++i)
            beg = beg->next;
        ListNode *first = beg->next, *cur = first, *prev = beg;
        int i = m;
        while (cur && i <= n) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            ++i;
        }
        // cur here behaves as right boundary 'end'
        first->next = cur;
        beg->next = prev;
        return dummy.next;
    }
};
