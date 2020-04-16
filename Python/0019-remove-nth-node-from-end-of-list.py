# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# its better to create dummy node always
# Time O(n)
# Space O(1)
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head

        slow, fast = dummy, dummy

        for i in range(n):
            fast = fast.next


        while fast.next:
            fast, slow = fast.next, slow.next

        slow.next = slow.next.next

        return dummy.next
