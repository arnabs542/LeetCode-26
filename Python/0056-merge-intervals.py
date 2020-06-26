# Time:  O(nlogn)
# Space: O(1)

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return intervals
        intervals.sort(key= lambda x: x[0])
        iterator = iter(intervals)
        result = [next(iterator)]
        for cur in iterator:
            prev = result[-1]
            if cur[0] <= prev[1]:
                prev[1] = max(cur[1], prev[1])
            else:
                result.append(cur)
        return result
