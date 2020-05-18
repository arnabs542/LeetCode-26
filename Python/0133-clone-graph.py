# Time:  O(n)
# Space: O(n)
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None

        cloned_node = Node(node.val)

        cloned, stack = {node:cloned_node}, [node]

        while stack:
            cur = stack.pop()
            for neighbor in cur.neighbors:
                if neighbor not in cloned:
                    stack.append(neighbor)
                    cloned_neighbor = Node(neighbor.val)
                    cloned[neighbor] = cloned_neighbor
                cloned[cur].neighbors.append(cloned[neighbor])

        return cloned[node]







# Notes: Use dictionary cloned to search in constant time
# DFS runtime V+E , E could be O(V^2) in case of dense graph
# cloned dict contains visited and to be visited ie stack nodes
