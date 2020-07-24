# Time:  O(n^k), a*h where a (branches) = n and h(height) = k (if only 1's)
# Space: O(k), assuming 1 is chosen at each level.
# where k = target, n = len(candidates)
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:


        def dfs(start, intermediate, target):
            if target == 0:
                result.append(list(intermediate))
            while start < len(candidates) and candidates[start] <= target:
                    intermediate.append(candidates[start])
                    dfs(start, intermediate, target - candidates[start])
                    intermediate.pop()
                    start += 1

        result = []
        candidates.sort()
        dfs(0, [], target)
        return result



# Notes:
# Since we are looking for combinations not permutations,
# we need start to keep track of index from where we start at
# each level of tree
