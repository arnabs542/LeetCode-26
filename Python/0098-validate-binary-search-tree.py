# Time:  O(n)
# Space: O(n)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Recursion
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def helper(root, low, high):
            if root is None:
                return True
            # checking if root.val > low but < high
            return low < root.val and root.val < high and helper(root.left, low, root.val) and helper(root.right, root.val, high)

        return helper(root, float("-inf"), float("inf"))
