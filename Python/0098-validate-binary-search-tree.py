# Time:  O(n)
# Space: O(n)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Recursion Preorder
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def helper(root, low, high):
            if root is None:
                return True
            # checking if root.val > low but < high
            return low < root.val and root.val < high and helper(root.left,\
            low, root.val) and helper(root.right, root.val, high)

        return helper(root, float("-inf"), float("inf"))


# Inorder Traversal
# Time O(n)
# Space O(h)
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        left_child_val = float("-inf")
        cur = root
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                if cur.val <= left_child_val:
                    return False
                left_child_val = cur.val
                cur = cur.right
        return True

"""
At each step we check if the current node's value is less than
the right most node of the left subtree.
"""
