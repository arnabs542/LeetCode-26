# Time: O(n*2^n)
# Space: O(n*2^n), to keep all the subsets of length n,
# since each of n elements could be present or absent.
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def dfs(start, size, cur):
            if size == 0:
                result.append(cur[:])
                return

            while start < len(nums):
                cur.append(nums[start])
                dfs(start+1, size-1, cur)
                cur.pop()
                start += 1

        result = []
        for size in range(len(nums)+1):
            dfs(0, size, [])
        return result


# With little optimization
# Time: O(2^n)
# Space: O(n*2^n)
# no need to do a for loop for backTrack method, simply do the
# following will work because when processing backTrack for
# len = n, it will also process len 0, 1.... n-1
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start, cur):
            result.append(cur[:])

            while start < len(nums):
                cur.append(nums[start])
                backtrack(start+1, cur)
                cur.pop()
                start += 1

        result = []
        backtrack(0, [])
        return result


# Notes:
# Why cur[:]?
# Ans: curr is a list, that is mutable in Python. You modify the original
# object with each append and pop. Therefore you want to save/preserve
# the momentary state of curr when you append it to the output so you
# create a copy of it by slicing.




# Time:  O(n * 2^n)
# Space: O(1)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        for i in range(len(nums)):
            size = len(result)
            # append elem to lists already
            # present in result
            for j in range(size):
                # make a copy
                result.append(list(result[j]))
                # add new elem
                result[-1].append(nums[i])

        return result

# Notes:
# Using [1, 2, 3] as an example, the iterative process is like:
# Initially, one empty subset [[]]
# Adding 1 to []: [[], [1]];
# Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
# Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3],
# [1, 3], [2, 3], [1, 2, 3]].

# To do: Bit manipulation method
