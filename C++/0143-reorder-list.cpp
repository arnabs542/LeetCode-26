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
    void reorderList(ListNode* head) {

        if (head==NULL || head->next == NULL)
            return;
        ListNode* prev = NULL;
        auto slow = head;
        auto fast = head;

        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        auto l1 = head;
        auto l2 = reverseList(slow);

        ListNode dummy {0};
        auto current = &dummy;
        while(l1 && l2){
            auto l1Next = l1->next;
            auto l2Next = l2->next;

            current->next = l1;
            current = l1;
            l1 = l1->next;

            current->next = l2;
            current = l2;
            l2 = l2->next;
        }
    }
private:
    ListNode* reverseList(ListNode* head){
        auto current=head;
        ListNode *prev = NULL;

        while(current){
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};



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
    void reorderList(ListNode* head) {

        if (head==NULL || head->next == NULL)
            return;
        ListNode* prev = NULL;
        auto slow = head;
        auto fast = head;

        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        auto l1 = head;
        auto l2 = reverseList(slow);

        //ListNode dummy {0};
        //auto current = &dummy;
        while(l1){
            ListNode *l1Next = l1->next;
            ListNode *l2Next = l2->next;
            l1->next = l2;
            if(!l1Next)
                break;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
    }
private:
    ListNode* reverseList(ListNode* head){
        auto current=head;
        ListNode *prev = NULL;

        while(current){
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};
