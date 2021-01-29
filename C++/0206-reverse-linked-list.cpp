// Tags: Linked-list Amazon
// Time O(n)
// Space O(1)
// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head ;
            head = next;
        }
        return prev;
    }
};



// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head){
      // !head for [] case
      if(!head || head->next==NULL){
        return head;
      }
      // preorder as if we do postorder, we won't be able
      // to traverse the linked list
      auto newHead = reverseList(head->next);
      // put a reverse pointer between current
      // & next node
      head->next->next = head;
      // null out the previous (forward) pointer
      head->next = NULL;
      return newHead;
    }
};
