import collections
class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:

        def dfs(node, parent):
            counter = collections.Counter()

            for child in adj[node]:
                if child == parent:
                    continue
                counter += dfs(child, node)

            counter[labels[node]] += 1
            result[node] = counter[labels[node]]

            return counter


        adj = collections.defaultdict(list)
        for a,b in edges:
            adj[a].append(b)
            adj[b].append(a)
        result = [0] * n
        dfs(0, 0)
        return result


# Notes:
# Postorder traversal
# Parent is needed to skip node to parent edge
