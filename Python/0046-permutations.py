# Time:  O(n * n!)
# Space: O(n)

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        used = [False]*len(nums)

        # cur: list representing permutation in current branch
        def dfs(cur):
            if len(cur) == len(nums):
                result.append(cur[:])
                return

            for i in range(len(nums)):
                if not used[i]:
                    used[i] = True
                    cur.append(nums[i])
                    dfs(cur)
                    used[i] = False
                    cur.pop()
        dfs([])
        return result
