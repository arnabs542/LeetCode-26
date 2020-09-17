# faster solution than c++ one (less operations)
# Time:  O(n)
# Space: O(n)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Using two lists
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        result, curr_lev = [], [root]
        # vals contain values of visited nodes
        # stop when there are not more nodes in curr_lev
        while curr_lev:
            next_lev, vals = [], []
            for node in curr_lev:
                vals.append(node.val)
                if node.left:
                    next_lev.append(node.left)
                if node.right:
                    next_lev.append(node.right)
            curr_lev = next_lev
            result.append(vals)

        return result


# Using Queue
import collections
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        que = collections.deque([root])
        result = []
        while que:
            lev = []
            size = len(que)
            # can't say range(len(que)) as it keeps changing
            for _ in range(size):
                node = que.popleft()
                lev.append(node.val)
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
            result.append(lev)
        return result
