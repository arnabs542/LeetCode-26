//Time O(n)
//Space O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head;
        auto fast = head;


        while (n>0){
            fast = fast->next;
            --n;
        }
        // n = length of linked list and we have to remove the head
        if (fast == nullptr)
        return head->next;

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        auto toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return head;
    }
};
