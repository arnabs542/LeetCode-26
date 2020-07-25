# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|), multiple versions for same vertex
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        adj = collections.defaultdict(list)
        for (u, v), p in zip(edges, succProb):
            adj[u].append((v, p))
            adj[v].append((u, p))
        # 1 as probability is multiplied
        max_heap = [(-1.0, start)]
        # result stores dist from start
        result, visited = collections.defaultdict(float), set()
        result[start] = 0
        while max_heap and len(visited) != len(adj):
            cur, u = heapq.heappop(max_heap)
            if u in visited:
                continue
            visited.add(u)
            for v, w in adj[u]:
                if v in visited:
                    continue
                # previous dist is larger
                if v in result and result[v] >= -cur*w:
                    continue
                # increase key using result dict
                result[v] = -cur*w
                heapq.heappush(max_heap, (-result[v], v))
        return result[end]
