// Time: O(n * 2 ^ n). We enumerate 2 ^ n trees and traverse each tree once.
// Space: O(n). Because it's a tree, the number of edges is n - 1,
// so we our adjacency list need n + n-1 space.
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> res(n - 1);
        for (auto &edge: edges) {
            // labelling changed to 0 to n-1
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        for (int mask = 0; mask < 1 << n; ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & 1 << i) {
                    // for node present in subset
                    int nodes = 0, dia = 0;

                    // making the bit corresponding to parent(current node) = zero
                    dfs(adj, mask ^ (1 << i), i, nodes, dia);
                    // number of nodes visited and diameter returned

                    // nodes in the subset form a tree (ie. connected graph possible)
                    // dia > 0 as res[dia - 1]
                    if (dia > 0 && nodes == (bitset<16> (mask)).count())
                        ++res[dia - 1]; // -1 as 0 indexed
                    break; // only visit any one node
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &adj, int mask, int u, int &n, int &res) {
        int maxDepth = 0;
        ++n;
        for (auto v: adj[u]) {
            if (mask & (1 << v)) {
                int childDepth = dfs(adj, mask ^ (1 << v), v, n, res);
                // + 1 for root & -1 for getting edges
                res = max(res, childDepth + maxDepth + 1 - 1);

                // automatically finds maxDepth1st and maxDepth2nd
                maxDepth = max(maxDepth, childDepth);
            }
        }
        // number of nodes (including root)
        return maxDepth + 1;
    }
};

/*
• Since n <= 15, there is a maximum 2^15 subset of cities numbered from 1 to n.
(for each number(node), there are two choices: included in subset or not included)
• For each of subset, we calculate the maximum distance between any two cities in our subset.
• Maximum distance between any two cities in our subset (subset must be a subtree) is the diameter of the tree.
*/
