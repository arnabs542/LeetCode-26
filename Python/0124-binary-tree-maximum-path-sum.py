# Time:  O(n)
# Space: O(h), h is height of binary tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxSum = float("-inf")
    def maxPathSum(self, root: TreeNode) -> int:
        self.PathSum(root)
        return self.maxSum


    def PathSum(self, node):
        if node is None:
            return 0

        left = max(0, self.PathSum(node.left))
        right = max(0, self.PathSum(node.right))

        self.maxSum = max(self.maxSum, left + right + node.val)

        return max(left,right) + node.val


# Notes:
# Unlike iterative dfs using stack, here we do work after returning
