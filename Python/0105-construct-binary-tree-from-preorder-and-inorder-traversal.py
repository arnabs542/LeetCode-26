# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# pythonic solution
# Time O(n)
# Space O(n)
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




class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        # inStart and inEnd denotes the range of nodes that fall under the
        # current subtree rooted at preStart
        def helper(preStart, inStart, inEnd):
            if inStart > inEnd:
                return None

            root = TreeNode(preorder[preStart])
            inIndex = 0
            for i in range(inStart, inEnd+1):
                if root.val == inorder[i]:
                    inIndex = i

            root.left = helper(preStart + 1, inStart, inIndex - 1)
            root.right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd)
            return root

        return helper(0, 0, len(inorder) - 1)

"""
We are doing dfs preorder traversal to build tree.

iter(list) works in case of prorder traversals.
"""
