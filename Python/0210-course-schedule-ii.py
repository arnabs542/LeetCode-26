# Time:  O(|V| + |E|)
# Space: O(|V|), without adjacency list
# DFS finding cycle
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        visit = [0 for _ in range(numCourses)]
        result = []

        for i, j in prerequisites:
            adj[j].append(i)
        def dfs(u):
            if visit[u] == -1:
                return False

            if visit[u] == 1:
                return True

            visit[u] = -1

            for v in adj[u]:
                if not dfs(v):
                    return False

            result.append(u)
            visit[u] = 1
            return True
        for i in range(numCourses):
            if not dfs(i):
                return []
        result.reverse()
        return result



# Topological Sort using BFS
# Time: O(V+E)
# Space: O(V), without adjacency list
# Kahn's algorithm
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = [0 for _ in range(numCourses)]
        result = []

        for i, j in prerequisites:
            adj[j].append(i)
            indegree[i] += 1
        q = collections.deque([])
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        while q:
            u = q.popleft()
            result.append(u)

            for v in adj[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        return result if len(result) == numCourses else []
