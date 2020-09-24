# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Time:  O(n)
# Space: O(n)
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        result = []
        prev = [root]
        while prev:
            cur = []
            vals = []
            for node in prev:
                vals.append(node.val)
                if node.left:
                    cur.append(node.left)
                if node.right:
                    cur.append(node.right)
            prev = cur
            # or vals.reverse()
            result.append(vals[::-1] if len(result) % 2 else vals)
        return result
