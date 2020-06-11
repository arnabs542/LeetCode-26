# Time:  O(nlogn) for total n addNums, O(logn) per addNum, O(1) per findMedian.
# Space: O(n), total space
# Heap Solution
import heapq
# or from heapq import heappush, heappop
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_heap = []
        self.max_heap = []


    def addNum(self, num: int) -> None:
        if not self.max_heap or num > -self.max_heap[0]:
            heapq.heappush(self.min_heap, num)
            if len(self.min_heap) > len(self.max_heap) + 1:
                heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))
        else:
            heapq.heappush(self.max_heap, -num)
            if len(self.max_heap) > len(self.min_heap):
                heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))

    def findMedian(self) -> float:
        return (self.min_heap[0] - self.max_heap[0])/2 if len(self.min_heap) == len(self.max_heap)\
                else self.min_heap[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
