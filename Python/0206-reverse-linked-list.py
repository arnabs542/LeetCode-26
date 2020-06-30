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
        # not head is for empty list
        if not (head) or not (head.next):
            return head

        newHead = self.reverseList(head.next)
        # we correct pointers while returning
        # next elem point to head/cur
        head.next.next = head
        # head/cur points to None
        head.next = None
        # the end of ll gives new_head and is
        # used by the start of ll
        return newHead

Notes:
head represents current node.
