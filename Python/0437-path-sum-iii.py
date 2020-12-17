# Tags: Amazon Tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Brute force solution
# Time: O(h*n), O(nlogn) (balanced tree) to O(n^2) (one sided tree)
# Space: O(h), O(logn) (balanced tree) to O(n) (single sided tree)
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.numOfPaths = 0
        # 1st layer dfs to go through each node
        self.pathSumFrom(root, sum)
        return self.numOfPaths

    # traverse through the tree
    # At each node, call test()
    def pathSumFrom(self, node, target):
        if node is None:
            return
        # order doesn't matter here
        # can even do postorder
        self.test(node, target)
        self.pathSumFrom(node.left, target)
        self.pathSumFrom(node.right, target)

    # dfs to find paths that sum == target starting for that node
    def test(self, node, target):
        if node is None:
            return

        if node.val == target:
            self.numOfPaths += 1

        self.test(node.left, target - node.val)
        self.test(node.right, target - node.val)
# Notes:
# the master theorem for "pathSumFrom" is T(N) = 2T(N/2)+O(1),
# and with call to "test" is T(N)=2T(N/2)+O(N), where the O(N)
# is from the result of "test". So it's O(N log N). 
#
# Detailed Explanation:
# For a balanced tree:
# It is O(N*) or T(N*), but N* is not the N (total number of nodes in tree),
# it is number of nodes in SUBtree for which pathSumFrom is called for.
# In each level in tree, as you go down, N* is halved. Finally you call pathSumFrom
# for the leaves whose cost is T(1) (as N* is 1).
# But yes, you call pathSumFrom at level L for 2^L nodes/subtrees.
# So at every level L total number of operations is T(N/ 2^L) * 2^L
# L = 0 means the root of the tree. T(N/1) * 1 --> O(N)
# L = H (height, LogN) means the leaves. T(N/2^LogN) * 2^LogN -> T(1) * N --> O(N)
# So at every level L total number of operations is O(N)
# Then next question is how many levels we have to visit ? That s the height of
# tree, log N.
# Hence we have O(NLogN)



# Time:  O(n), as we traverse once
# Space: O(n), extra space due to the dictionary
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dfs(node, running_sum):
            nonlocal result
            if not node:
                return

            running_sum += node.val

            # if this appeared before in tree above
            # there would be sum_count[running_sum-sum]
            # number of path having target sum and ending
            # at current node
            if running_sum - sum in sum_count:
                result += sum_count[running_sum-sum]

            # update count
            sum_count[running_sum] += 1

            dfs(node.left, running_sum)
            dfs(node.right, running_sum)

            # when we move to right branch after
            # returning from current left branch,
            # current running_sum is no longer
            # valid
            sum_count[running_sum] -= 1

        result = 0
        # sum_count will either be 1 or 0 (to check)
        sum_count = defaultdict(int)
        sum_count[0] = 1
        dfs(root, 0)

        return result
