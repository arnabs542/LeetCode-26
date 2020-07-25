# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Time:  O(n)
# Space: O(1)
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head, head

        # find meeting point
        # LOOP_SIZE - k steps into the linked list
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                break

        # no meeting point and therefore no loop
        if not fast or not fast.next:
            return None

        slow = head
        while slow is not fast:
            slow = slow.next
            fast = fast.next

        return fast
