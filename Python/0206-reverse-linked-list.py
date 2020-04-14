# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Time O(n)
# Space O(1)
# iterative
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next

        return prev

# recursive
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not (head) or not (head.next):
            return head

        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None

        return newHead
