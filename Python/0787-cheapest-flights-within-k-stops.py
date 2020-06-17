# Time:  O((|E| + |V|* log|V|)
# Space: O(|E| + |V|) = O(|E|)
import heapq
import collections
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        adj = collections.defaultdict(dict)
        for u, v, w in flights:
            adj[u][v] = w
        min_heap = [(0, src, K + 1)]
        while min_heap:
            cost, u, k = heapq.heappop(min_heap)
            if u == dst:
                return cost
            if k > 0:
                # for keys in f[i]
                for v in adj[u]:
                    heapq.heappush(min_heap, (cost + adj[u][v], v, k - 1))

        return -1


# Notes:
# could have used defaultdict(list)
# can also use [[] for _ in range(n)]
