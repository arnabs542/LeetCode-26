# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Time:  O(n)
# Space: O(h)
# DFS, Recursive solution, Post order, Down to top
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is not None:
            root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)

        return root


# Time:  O(n)
# Space: O(h)
# DFS Iterative Stack solution (list as stack).
class Solution2:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is not None:
            nodes = []
            nodes.append(root)

            while nodes:
                node = nodes.pop()
                node.left, node.right = node.right, node.left

                if node.left is not None:
                    nodes.append(node.left)

                if node.right is not None:
                    nodes.append(node.right)

        return root



# Time:  O(n)
# Space: O(w), w is max number of nodes at a levels
# w = (n+1)/2 in case of full binary tree
# BFS Iterative Queue solution .
from collections import deque
class Queue:
    def __init__(self):
        self.data = deque()

    def push(self,x):
        self.data.append(x)

    def peek(self):
        return self.data[0]

    def pop(self):
        return self.data.popleft()

    def size(self):
        return len(self.data)

    def empty(self):
        return len(self.data) == 0

class Solution3:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is not None:
            nodes = Queue()
            nodes.push(root)

            while not nodes.empty():
                node = nodes.pop()
                #.pop(0) if list
                node.left, node.right = node.right, node.left

                if node.left is not None:
                    nodes.push(node.left)

                if node.right is not None:
                    nodes.push(node.right)

        return root


# from queue import Queue - put(), get()
