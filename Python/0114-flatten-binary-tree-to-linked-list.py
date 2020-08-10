# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Time:  O(n)
# Space: O(h), h is height of binary tree
# Recursive post order traversal
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # helper function takes in the previous head, do the flattening
        # and returns the head of flattened binary tree
        def dfs(root, prev):
            if not root:
                # or None
                return prev

            # we call root.right first to get a tree as asked in the
            # question
            prev = dfs(root.right, prev)
            prev = dfs(root.left, prev)

            root.right = prev
            root.left = None

            return root

        return dfs(root, None)

# Notes:
# prev can also be declared as a global variable. In that case,
# dfs takes only one argument and doesn't need to return anything.

# To do: Using morris traversal
# refer https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
