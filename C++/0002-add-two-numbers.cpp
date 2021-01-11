// Tags: Linked-list Amazon
// Time: O(n)
// Space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto cur = &dummy;
        int carry = 0;
        // iterate left to right and carry to right
        while (l1 || l2 || carry) {
            // there may be case when both l1 & l2 are nullptr
            // but carry is 1
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int val = a + b + carry;
            // capture 0th digit and extend linked list
            cur->next = new ListNode(val%10);
            // capture 1's digit
            carry = val/10;
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};
