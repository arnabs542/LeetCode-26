// Tags: Linked-list Amazon
// Time: O(n)
// Space: O(1)
// Reusing idea of 0025-reverse-nodes-in-k-group
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // dummy is required as m could be 1 (so we'd need a node to act as beg)
        ListNode dummy;
        dummy.next = head;
        // beg is left boundary node
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
/*
dummy -> 1 -> 2 -> 3 -> 4 -> 5
        beg  first          end
           <- 2 <- 3 <- 4
                        prev cur
         1 -> 4 -> 4 -> 2 -> 5

Edge cases:
* m = 1 : create dummy node
* n = last node, cur will become nullptr in last iter : first->next = cur still works
*/
