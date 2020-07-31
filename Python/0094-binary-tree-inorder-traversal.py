# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Iterative
# Time O(n)
# Space O(h)
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        result = []
        stack = []
        cur = root
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                if not cur:
                    result.append('null')
                else:
                    result.append(cur.val)
                cur = cur.right
        return result



# Recursive
# Time O(n), T(n) = 2*T(n/2)+1
# Space O(h), worst case O(n), average case O(logn)
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        def helper(root):
            nonlocal res
            if not root:
                return

            helper(root.left)
            res.append(root.val)
            helper(root.right)

        if not root:
            return []
        res = []
        helper(root)
        return res
