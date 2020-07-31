Time: O(nW), W = 71, so O(n)
Space: O(n+W)
# Next Array
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        nxt = [float('inf')] * 102
        ans = [0] * len(T)
        for i in range(len(T) - 1, -1, -1):
            warmer_index = min(nxt[t] for t in range(T[i] + 1, 102))

            if warmer_index < float('inf'):
                ans[i] = warmer_index - i

            nxt[T[i]] = i

        return ans


# Time:  O(n)
# Space: O(n), worst case (no warmer temp)
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        result = [0] * len(T)
        stack = []
        for i in range(len(T)):
            while stack and  T[stack[-1]] < T[i]:
                idx = stack.pop()
                result[idx] = i - idx
            stack.append(i)
        return result
