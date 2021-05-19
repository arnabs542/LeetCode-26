// Tags: DFS Tree Google
// Time: O(n)
// Space: O(n)
class Solution {
    // for postorder ans[i]: sum of distances between node i and all other nodes present in
    // the subtree rooted at i
    // for preorder ans[i]: sum of the distances between node i and all other nodes
    vector<int> ans;
    // count[i]: number of nodes in subtree rooted at i
    vector<int> count;
    vector<vector<int>> adj;
    
    void postorder(int u, int par) {
        for (int v : adj[u]) {
            if (v == par)
                continue;
            postorder(v, u);
            count[u] += count[v];
            // distance to all nodes in subtree rooted at v increase by 1
            // (and there are count[v] nodes in the subtree)
            ans[u] += ans[v] + count[v];
        }
    }
    
    void preorder(int u, int par) {
        for (int v : adj[u]) {
            if (v == par)
                continue;
            // count[v] number of nodes get closer (those present in subtree rooted at v) by 1
            // all other nodes n - count[v] (not present in the subtree) get farther by 1
            ans[v] = ans[u] - count[v] + (count.size() - count[v]);
            preorder(v, u);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.assign(n, 0);
        // initially only root included
        count.assign(n, 1);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // get ans[0] & count[i] for every node i
        postorder(0, -1);
        // reset ans[i] for all nodes 1, 2, ..... n - 1
        // then use ans[0] to update ans[i] for these nodes
        preorder(0, -1);
        return ans;
    }
};
/*
Intuition:
What if given a tree, with a certain root 0?
In O(N) we can find sum of distances in tree from root and all other nodes.

Now for all N nodes?
Of course, we can do it N times and solve it in O(N^2) but it's not what we want.

When we move our root from one node to its connected node, nodes in one part get closer,
nodes in the other part get further.

If we know exactly how many nodes are present in both parts, we can solve this problem.

With one single traversal in tree, we should get enough information for it and don't need to
do it again and again.


Algo:
1. Let's solve it with node 0 as root.

2. Post order dfs traversal, update count and ans:
    count[root] = sum(count[v]) + 1
    ans[root] = sum(ans[v]) + sum(count[v])

3. Pre order dfs traversal, update ans: 
    ans[v] = ans[root] - count[v] + N - count[v]
*/
