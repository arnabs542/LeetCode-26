# Time:  create prefix_sum: O(n)
#        pickIndex: O(logn)
# Space: O(n)

class Solution:

    def __init__(self, w: List[int]):
        self.prefix_sum = []
        prefix_sum = 0
        for weight in w:
            prefix_sum += weight
            self.prefix_sum.append(prefix_sum)
        self.total_sum = prefix_sum

    def pickIndex(self) -> int:
        random_num = (self.total_sum) * random.random()
        # can't use random.randint(0, self.prefix_sum[-1]-1)
        left, right = 0, len(self.prefix_sum) - 1
        while left < right:
            mid = left + (right - left)//2
            if random_num > self.prefix_sum[mid]:
                left = mid + 1
            else:
                right = mid

        return left



# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
