# Time O(n)
# Space O(n)
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        def preOrder(node):
            if node:
                vals.append(str(node.val))
                preOrder(node.left)
                preOrder(node.right)
            else:
                vals.append('#')

        vals = []
        preOrder(root)
        return ' '.join(vals)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def preOrder():
            val = next(vals)
            if val == '#':
                return None
            node = TreeNode(int(val))
            node.left = preOrder()
            node.right = preOrder()
            return node

        vals = iter(data.split())
        return preOrder()

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
