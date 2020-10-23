// Tags: Premium
// Time: O(n), where n is the number of edges in the tree
// Space: O(n)
class Solution {
    int diameter = 0;
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (const auto &edge: edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        dfs(0, -1, graph);
        return diameter;
    }

    int dfs(int root, int parent, unordered_map<int, unordered_set<int>> &graph)
    {
        int maxDepth1st = 0, maxDepth2nd = 0;
        for (auto &child: graph[root]) {
            if (child == parent)
                continue;
            int childDepth = dfs(child, root, graph);
            if (childDepth > maxDepth1st) {
                maxDepth2nd = maxDepth1st;
                maxDepth1st = childDepth;
            } else if (childDepth > maxDepth2nd) {
                maxDepth2nd = childDepth;
            }
        }
        // number of nodes in the longest path including root
        int longestPathThroughRoot = maxDepth1st + maxDepth2nd + 1;

        // number of edges in a tree = V - 1;
        diameter = max(diameter, longestPathThroughRoot - 1);

        // number of nodes on longest side (including root)
        return maxDepth1st + 1;
    }
};

/*
(Similar to max path sum of binary tree);
Travese all the nodes of the tree.
The diameter of the tree is maximum of the longest path through each node.
Longest path through a node is sum of top 2 depths of children's tree.
*/
