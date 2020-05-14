# pythonic solution
# Time O(n)
# Space O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        preorder_iterator = iter(preorder)
        inorder_lookup = {n: i for i, n in enumerate(inorder)}

        def helper(inStart, inEnd):
            if inStart > inEnd:
                return None

            root_val = next(preorder_iterator)
            root = TreeNode(root_val)
            idx = inorder_lookup[root_val]
            root.left = helper(inStart, idx-1)
            root.right = helper(idx+1, inEnd)
            return root

        return helper(0, len(inorder)-1)
