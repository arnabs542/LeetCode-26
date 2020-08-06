# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# First attempt: Time limit exceeded
# Time: O(exponential)
# Space: O(h)
# Post order traversal
class Solution:
    def rob(self, root: TreeNode) -> int:
            if not root:
                return 0

            val = 0

            if root.left:
                val += self.rob(root.left.left) + self.rob(root.left.right)

            if root.right:
                val += self.rob(root.right.left) + self.rob(root.right.right)

            return max(val + root.val, self.rob(root.left) + self.rob(root.right))



# DP solution 1 (memoization): Time limit exceeded
# Time: O(n)
# Space: O(n), stack cost of recursion not counted
class Solution:
    def rob(self, root: TreeNode) -> int:

            def robSub(root):
                if not root:
                    return 0
                if root in node_map:
                    return node_map[root]

                val = 0

                if root.left:
                    val += self.rob(root.left.left) + self.rob(root.left.right)

                if root.right:
                    val += self.rob(root.right.left) + self.rob(root.right.right)

                val = max(val + root.val, self.rob(root.left) + self.rob(root.right))
                node_map[root] = val
                return val

            node_map = {}
            return robSub(root)

# Notes:
# In step I, we only considered the aspect of "optimal substructure",
# but think little about the possibilities of overlapping of the subproblems.
# For example, to obtain rob(root), we need rob(root.left), rob(root.right),
# rob(root.left.left), rob(root.left.right), rob(root.right.left),
# rob(root.right.right); but to get rob(root.left), we also need
# rob(root.left.left), rob(root.left.right), similarly for rob(root.right).
# The naive solution above computed these subproblems repeatedly, which
# resulted in bad time performance. Now if you recall the two conditions for
# dynamic programming (DP): "optimal substructure" + "overlapping of subproblems",
# we actually have a DP problem. A naive way to implement DP here is to
# use a hash map to record the results for visited subtrees.



# DP solution 2: Accepted
# Time: O(n)
# Space: O(1), stack cost of recursion not counted
# O(h) including stack
class Solution:
    def rob(self, root: TreeNode) -> int:

            def robSub(root):
                if not root:
                    return (0, 0)
                left = robSub(root.left)
                right = robSub(root.right)
                a = max(left[0], left[1]) + max(right[0], right[1])
                # root not chosen in both left and right subtree
                b = root.val + left[0] + right[0]
                return (a, b)
            return max(robSub(root))

# Notes:
# Ref:https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
