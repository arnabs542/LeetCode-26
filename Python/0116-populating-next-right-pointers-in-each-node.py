"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
# Time: O(n)
# Space: O(n)
# Iterative, level order traversal
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        que = collections.deque([root])
        while que:
            size = len(que)
            for i in range(size):
                node = que.popleft()
                node.next = que[0] if i < size - 1 else None
                if node.left and node.right:
                    que.append(node.left)
                    que.append(node.right)
        return root


# Time:  O(n)
# Space: O(1)
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = root
        while head:
            cur = head
            # do until the second last level
            while cur and cur.left:
                # add link between left and right childs
                cur.left.next = cur.right
                # add link between right child and left child
                # of right sibling
                if cur.next:
                    cur.right.next = cur.next.left
                cur = cur.next
            # move to next level
            head = head.left
        return root


# Time:  O(n)
# Space: O(logn), height of tree (stack)
# Recusion, dfs
class Solution:
    def connect(self, root: 'Node') -> 'Node':
            if not root or not root.left:
                return root
            if root.left:
                root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
            self.connect(root.left)
            self.connect(root.right)
            return root
