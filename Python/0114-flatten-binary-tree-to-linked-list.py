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
                # do nothing, just return the head of previous flattened list
                return prev

            # we call root.right first to get a tree as asked in the
            # question
            prev = dfs(root.right, prev)
            # give the head of already flattened list to left subtree
            prev = dfs(root.left, prev)
            # flatten current node
            root.right = prev
            root.left = None

            # return the head of flattened list
            return root

        return dfs(root, None)

# Notes:
# prev always point to the head of the flattened list.
# prev can also be declared as a global variable. In that case,
# dfs takes only one argument and doesn't need to return anything.
"""
flatten from tail to head (as per linkedlist)
    1
   / \
  2   5
 / \   \
3   4   6
-----------
pre = 5
cur = 4

    1
   /
  2
 / \
3   4
     \
      5
       \
        6
-----------
pre = 4
cur = 3

    1
   /
  2
 /
3
 \
  4
   \
    5
     \
      6
-----------
cur = 2
pre = 3

    1
   /
  2
   \
    3
     \
      4
       \
        5
         \
          6
-----------
cur = 1
pre = 2

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
"""



# Similar to morris traversal, flatten from top to down (iterative)
# Time: O(n), each node is visited at most twice
# Space: O(1), inplace
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        cur = root
        while cur:
            if cur.left:
                # find right most leaf of left subtree
                leaf = cur.left
                while leaf.right:
                    leaf = leaf.right
                # attach right subtree to leaf's right
                leaf.right = cur.right
                # flatten current node
                cur.right = cur.left
                cur.left = None
            # move to next node
            cur = cur.right
        return root
