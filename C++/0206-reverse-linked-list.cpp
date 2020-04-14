/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Time O(n)
// Space O(1)
// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;

        while(head){
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
      if(!head || head->next==NULL){
        return head;
      }
      auto newHead = reverseList(head->next);
      head->next->next = head;
      head->next = NULL;
      return newHead;
    }
};
