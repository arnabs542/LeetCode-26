# Time:  O(n)
# Space: O(h)
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # if not root or root is p or root == q:
        if root in (None, p, q):
            # return either null or p or q
            return root

        left, right = [self.lowestCommonAncestor(child, p, q) \
                       for child in (root.left, root.right)]

        return root if left and right else left or right



# Notes:
# Think of a node in each call as a subtree rooted at
# that node

# If the current (sub)tree contains both p and q,
# then the function result is their LCA. If only one of them
# is in that subtree, then the result is either one of them.
# If neither are in that subtree, the result is null/None/nil.
