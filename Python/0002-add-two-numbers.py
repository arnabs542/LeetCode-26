# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        cur, carry, = dummy, 0

        while l1 or l2:
            value = carry
            if l1:
                value += l1.val
                l1 = l1.next
            if l2:
                value += l2.val
                l2 = l2.next
            # carry can only me 0 or 1
            carry, value = divmod(value, 10)
            cur.next = ListNode(value)
            cur = cur.next
        if carry == 1:
            cur.next = ListNode(1)

        return dummy.next
