# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Time O(m*n), m is the number of nodes of s, n is the number of nodes of t
# Space O(h), h is the height of s
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:

        def isSame(x, y):
            if not x and not y:
                return True

            if not x or not y:
                return False

            return (x.val == y.val) and isSame(x.left, y.left) and isSame(x.right, y.right)

        def preOrderTraverse(s, t):
            return s and (isSame(s, t) or preOrderTraverse(s.left, t) or preOrderTraverse(s.right, t))

        return preOrderTraverse(s,t)



class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def isSame(s,t):
            if not s and not t:
                return True
            if not s or not t:
                return False
            return s.val == t.val and isSame(s.left, t.left) and isSame(s.right, t.right)

        return s and (isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t))

"""
We are checking if a tree rooted at s is same as tree rooted at t. If not,
we check if tree rooted at s.left or if tree rooted at s.right is same as t.
We keep doing this until we have checked every node in tree s.
"""
