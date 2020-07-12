# Time:  O(|V| + |E|)
# Space: O(|E|)

from collections import defaultdict, deque

# DFS finding cycle
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        # node v has not been visited
        visit = [0 for _ in range(numCourses)]

        for x,y in prerequisites:
            adj[y].append(x)

        # dfsTopSortExists
        def dfsAcyclic(u):
            # cycle exists as being visited node is called again
            # if node v is being visited (ie. in stack)
            if visit[u] == -1:
                return False

            # if node v has already been explored
            # (ie. was stuck & backtrack)
            if visit[u] == 1:
                return True

            # pushed to stack
            visit[u] = -1

            for v in adj[u]:
                if not dfsAcyclic(v):
                    return False

            # node has been explored now
            visit[u] = 1
            # poped from stack
            return True



        for i in range(numCourses):
            # if visit[i] == 0:
            # call dfs again from unvisited node
            if not dfsAcyclic(i):
                return False
        return True


# Notes:
# If there is a directed cycle, there is not topological ordering
# possible
# Unlike regular dfs which is preorder, it is postorder.
# Also, this is complicated to do using a iterative stack


# Time:  O(|V| + |E|)
# Space: O(|E|)
# complicated
from collections import defaultdict, deque

class Solution2:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        zero_in_degree = deque()
        in_degree, out_degree = defaultdict(set), defaultdict(set)

        for i,j in prerequisites:
            in_degree[i].add(j)
            # what are prereq's of i
            out_degree[j].add(i)
            # what j is prereq to

        for i in range(numCourses):
            if i not in in_degree:
                # doesn't have prereq's
                zero_in_degree.append(i)

        while zero_in_degree:
            prereq = zero_in_degree.popleft()

            if prereq in out_degree:
                # if it is prereq to other course
                for course in out_degree[prereq]:
                    in_degree[course].discard(prereq)
                    if not in_degree[course]:
                        zero_in_degree.append(course)

                del out_degree[prereq]

        if out_degree:
            return False

        return True
