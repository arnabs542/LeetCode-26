# Time:  O(m + n), element found at bottom left
# Space: O(1)
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m==0:
            return False
        n = len(matrix[0])
        if n==0:
            return False

        # start from top right
        # root of BST
        i, j = 0, n-1
        while i < m and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False


# Notes:
# It looks like a binary search tree
# see image:
# https://assets.leetcode.com/static_assets/discuss/uploads/files/1488858512318-monosnap-2017-03-06-22-48-17.jpg
#
# May be better solution exits:
# https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66154/is-theres-a-ologmlogn-solution-i-know-onm-and-omlogn
