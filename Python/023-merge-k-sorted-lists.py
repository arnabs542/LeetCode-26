# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Divide & Conquer Solution
# Time = O(n*logk)
# Space = O
# T(n) = 2T(n/2) + O(n)
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:

        def mergeTwoLists(l1, l2):
            dummy = curr = ListNode(0)

            while l1 and l2:
                if l1.val < l2.val:
                    curr.next = l1
                    l1 = l1.next
                else:
                    curr.next = l2
                    l2 = l2.next
                curr = curr.next

            curr.next = l1 if l1 else l2

            return dummy.next



        def mergeKListsHelper(lists, begin, end):
            if begin > end:
                return None
            if begin == end:
                return lists[begin]

            return mergeTwoLists(mergeKListsHelper(lists, begin, (begin+end)//2), mergeKListsHelper(lists, (begin+end)//2 + 1, end))

        return mergeKListsHelper(lists,0,len(lists)-1)
