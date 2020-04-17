# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# its better to create dummy node always
# This is because if the node to be deleted is the head node in
# one of the test case then slow, which points to the previous of 
# the node to be deleted will have nothing to point to
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
