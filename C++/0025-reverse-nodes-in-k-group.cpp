// Tags: Linked-list Amazon
// Time: O(n)
// Space: O(1)
// Recursive solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = head;
        int count = 0;
        // find the k+1 node
        while (new_head && count != k) {
            new_head = new_head->next;
            ++count;
        }
        if (count == k) {
            // if k+1 node is found
            // reverse list with k+1 node as head
            new_head = reverseKGroup(new_head, k);
            // head is head-pointer to direct part
            // new_head is head-pointer to reversed part
            // reverse current k-group
            /* Reversing approach: we pop a node from front of direct list & 
             prepend it to new reversed linked list we started from other end */
            while (count-- > 0) {
                ListNode* next = head->next;
                head->next = new_head;
                new_head = head;
                head = next;
            }
            // update head
            head = new_head;
        }
        return head;
    }
};



// Time: O(n)
// Space: O(1)
// Iterative solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        // left boundary node for first group
        ListNode* begin = &dummy;
        int i = 1;
        while (cur) {
            // kth node
            if (i % k == 0) {
                // returns left boundary node for the next group
                // (end node could also be nullptr)
                begin = reverse(begin, cur->next);
                cur = begin->next;
            } else {
                cur = cur->next;
            }
            ++i;
        }
        return dummy.next;
    }
private:
    // reverses the list between begin and end (excluding them)
    // (begin and end are boundary nodes)
    /* Reversing approach: iterate from left to right, keep reversing
       next pointers, when you reach end, set first.next = end
       (i.e. flip the list) */
    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* prev = begin;
        ListNode* first = begin->next;
        ListNode* cur = begin->next;
        while (cur != end) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        first->next = end;
        begin->next = prev;
        // first acts as begin node for the next group
        return first;
    }
};
