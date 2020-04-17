# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return


        def reverseList(head):
            prev = None
            curr = head

            while curr:
                nextNode = curr.next
                curr.next = prev
                prev = curr
                curr = nextNode

            return prev



        def merge(l1, l2):
            dummy = ListNode(0)
            current = dummy
            while l1 and l2:
                current.next, current, l1 = l1, l1, l1.next
                current.next, current, l2 = l2, l2, l2.next

#             while(l1):
#                 l1Next = l1.next
#                 l2Next = l2.next

#                 l1.next = l2

#                 # if length is odd, l1 will be shorter. Otherwise if the length is even, still this condition works.
#                 if l1Next == None:
#                     break

#                 l2.next = l1Next
#                 l1 = l1.next
#                 l2 = l2.next



        slow, prev, fast = head, None, head
        # getting to the middle of list
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        prev.next = None
        # l1 is the head of first half list
        # l2 is head of second half list reversed
        l1, l2 = head, reverseList(slow)

        merge(l1,l2)

        return head






# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return


        def reverseList(head):
            prev = None
            curr = head

            while curr:
                nextNode = curr.next
                curr.next = prev
                prev = curr
                curr = nextNode

            return prev



        slow, prev, fast = head, None, head
        # getting to the middle of list
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        prev.next = None
        # l1 is the head of first half list
        # l2 is head of second half list reversed
        l1, l2 = head, reverseList(slow)

        while l1:
            l1Next, l2Next = l1.next, l2.next
            l1.next = l2
            if not l1Next:
                break
            l2.next = l1Next
            l1, l2 = l1Next, l2Next


        return head
