/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Tags: Amazon Linked list Divide and conquer heap
// Divide & Conquer Solution
// Time = O(n*logk)
// Space = O(logk), due to recursion
// T(k) = 2T(k/2) + O(n), (master's theorem can't be used)
// Work done at each level = O(n)
// No. of levels = h = logk
// => T(k) = n*logk

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
// Space = O(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy {0};
        auto *curr = &dummy;

        // return true if a should be placed on left of b
        // then, reverse the inequative operator
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


// Heap solution without lambda function
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy {};
        ListNode *cur = &dummy;
        // max_heap by default, therefore pushing negative values
        priority_queue<pair<int, ListNode*>> min_heap;

        for (const auto &n: lists) {
            if (n)
                min_heap.push({-n->val, n});
        }

        while (!min_heap.empty()) {
            ListNode* node = min_heap.top().second;
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next)
                min_heap.push({-node->next->val, node->next});
        }
        return dummy.next;
    }
};

/*
Here we created a heap of size k. Then at each iteration we pop one elem and if that
particular elem has next elements in its linked list, we push that.
Continue until heap is empty.
*/



// Merge two by two solution, (Iterative Divide & Conquer)
// Time: O(n*logk)
// Space: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        int left = 0, right = lists.size() - 1;
        while (right > 0) {
            lists[left] = merge(lists[left], lists[right]);
            ++left;
            --right;
            if (left >= right)
                left = 0;
        }
        return lists[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
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
