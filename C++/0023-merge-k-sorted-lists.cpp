/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Divide & Conquer Solution
// Time = O(n*logk)
// Space = O
// T(n) = 2T(n/2) + O(n)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists,0,lists.size()-1);
    }
private:
    ListNode* mergeKListsHelper(const vector<ListNode*> &lists, int begin, int end){
        if (begin>end){
            return nullptr;
        }
        if (begin == end){
            return lists[begin];
        }
        // mergeTwoLists() is our O(n) combining step
        return mergeTwoLists(mergeKListsHelper(lists, begin, (begin+end)/2), mergeKListsHelper(lists, (begin+end)/2 +1, end));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy {0};
        ListNode *curr = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;

            }else{
                curr->next = l2;
                l2  = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;

    }
};
















// Heap Solution
// Time = O(n*logk)
// Space = O

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy {0};
        auto *curr = &dummy;

        auto cmp = [] (const ListNode *a, const ListNode *b){ return (b->val < a->val) ;};

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        for (const auto &n : lists){
            if(n){
                min_heap.emplace(n);
                // or .push(n);
            }
        }


        while(!min_heap.empty()){
            auto *node = min_heap.top();
            min_heap.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next){
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }
};
