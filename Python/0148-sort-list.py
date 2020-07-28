# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# D&C / Merge sort solution
# Recursion / Top-down approach
# Time: O(nlogn)
# Space: O(logn), height of tree/stack = logb(a)
class Solution:
    def sortList(self, head: ListNode) -> ListNode:

        def helper(low):
            if low is None:
                return None
            if low.next is None:
                return low
            slow, fast = low, low
            while fast and fast.next:
                prev = slow
                fast = fast.next.next
                slow = slow.next
            prev.next = None
            l1 = helper(low)
            l2 = helper(slow)
            return merge(l1, l2)

        def merge(l1, l2):
            dummy = ListNode(0)
            cur = dummy

            while l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next

            cur.next = l1 if l1 else l2
            return dummy.next

        return helper(head)

# Notes:
# Instead of adding the start and end of a list as adgument, we
# take just head of the list and put a null pointer where we want
# its end.

# D&C / Merge sort solution
# Recursion / Bottom-up approach
# Time: O(nlogn)
# Space: O(1)
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            # already sorted
            return head
        # finding length
        cur = head
        length = 0
        while cur:
            length += 1
            cur = cur.next
        step = 1
        dummy = ListNode(0)
        dummy.next = head
        # passes
        while step < length:
            # can't use cur = head
            # as head is pointer to original
            # list
            cur = dummy.next
            # tail of sorted list
            tail = dummy
            while cur:
                left = cur
                right = self._split(left, step)
                cur = self._split(right, step)
                # unlike other problem we don't need
                # head of sorted list but tail
                tail = self._merge(left, right, tail)
            step <<= 1
        return dummy.next

    # Puts a null after step len from head
    # and return the pointer to very next node
    def _split(self, head, step):
        i = 1
        while i <= step and head:
            prev = head
            head = head.next
            i += 1
        if not head:
            return None
        prev.next = None
        return head

    def _merge(self, l1, l2, tail):
        cur = tail
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        # get last node
        while cur.next:
            cur = cur.next
        return cur
