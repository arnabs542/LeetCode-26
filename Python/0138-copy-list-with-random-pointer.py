# Time:  O(n)
# Space: O(n)
# Using Hash Table
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        dummy = Node(0)
        curr, prev = head, dummy
        copies = {}
        while curr:
            copied = Node(curr.val)
            prev.next = copied
            copies[curr] = copied
            prev = prev.next
            curr = curr.next

        curr = head
        while curr:
            if curr.random:
                copies[curr].random = copies[curr.random]
            curr = curr.next
        return dummy.next



# Time:  O(n)
# Space: O(1)
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        # copy and combine copied list with original list
        curr = head
        while curr:
            copied = Node(curr.val)
            copied.next = curr.next
            curr.next = copied
            curr = copied.next

        # update random node in copied list
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next

        # split copied list from combined one
        # prev points to copied
        dummy = Node(0)
        curr, prev = head, dummy
        while curr:
            prev.next = curr.next
            curr.next = curr.next.next
            prev, curr = prev.next, curr.next
        return dummy.next


# Notes:
# for every node, the next node is its copy so hash
# table no longer required.
