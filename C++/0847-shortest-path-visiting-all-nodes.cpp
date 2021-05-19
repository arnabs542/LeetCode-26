// Tags: BFS DP Google
// Time: O(V + E), V = (2^n) * n, E = (2^n) * n * n (this node can go to atmost n - 1 nodes)
// (In worst case there are n * 2^n possible states in our search, and for each state we do
// work of order n)
// Space: O(V)
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        using T = tuple<int, int, int>;
        queue<T> q;
        unordered_set<string> visited;
        // or bool visited[1 << 12][12];
        for (int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0});
            visited.insert(to_string(1 << i) + '-' + to_string(i));
            // or visited[1 << i][i] = true;
        }
        
        while (!q.empty()) {
            auto [bitmask, u, cost] = q.front(); q.pop();
            
            if (bitmask == (1 << n) - 1)
                return cost;
            
            for (int v : graph[u]) {
                int nbitmask = bitmask | (1 << v);
                string t = to_string(nbitmask) + "-" + to_string(v);
                // or if (!visited[nbitmask][v])
                if (!visited.count(t)) {
                    visited.insert(t);
                    // or visited[nbitmask][v] = true;
                    q.push({nbitmask, v, cost + 1});
                }
            }
        }
        return -1;
    }
};
/*
Idea is to use Bfs to traverse the graph. Since all edges are weighted 1, then closer nodes
will always be evaluated before farther ones.

In order to represent a path, we use a combination of 3 values.
    1. bitMask: mask of all nodes visited so far. (we can only use a set instead which may
       lead to TLE)
    2. cur: current node we are on
    3. cost: total cost in the path
=> path ending at node 'cur' visiting all nodes in bitmask has length = 'cost'.

At each step, we remove element from the queue and see if we have covered all 12 nodes
in our bitMask. 

If we cover all nodes, we return the cost of the path immediately. (Since we are using
Bfs, this is guaranteed to be path with the lowest cost.)

Otherwise, we get all the neighbors of current node, and for each neighbor, set the Node
to visited in bitMask, and then add it back into the queue.

(In order to prevent duplicate/infinite paths "bitMask-cur" from being visited, we use a set
to store paths that we have visited before.
E.g.      1 - 2
          |
          3

path:       bitMask:  cur:
1             1        1
1->2          11       2
1->2->1       11       1
1->2->1->2    11       2 (prevented)
)
*/



// To do: Dp solution
