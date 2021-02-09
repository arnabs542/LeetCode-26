// Tags: DFS Amazon Backtracking Graph
// Time:  O(2^n)
// Space: O(n)
class Solution {
    void dfs(vector<vector<int>> &graph, int cur, vector<int> &path, vector<vector<int>> &res) {
            if (cur == graph.size() - 1) {
                res.push_back(path);
                return;
            }
            
            for (const auto &child: graph[cur]) {
                path.push_back(child);
                dfs(graph, child, path, res);
                path.pop_back();
            }
        }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path {0};
        dfs(graph, 0, path, res);
        return res;
    }
};

/*
Since directed, no need to worry about going back to parent
and since acyclic, no need to worry about forming cyclic with ancestor
as well. Therefore, we don't need to mark a node visited while performing
dfs.

Time complexity:
Suppose we have n nodes, labeled 0 to n-1.
Think of it as an array: [0, 1, 2, 3, 4, 5, 6, ..., n-1]

Now, we want to calculate how many paths there are from the 0th node to
the (n-1)th node.

Notice that each path of length k corresponds to some choice of (k - 1) 
nodes (out of n - 2 nodes) between 0 and (n-1).

How many paths of length k are there?
Answer is (n - 2 choose k - 1) for k = 1, 2,....,(n - 1)
=> Sigma (N choose R) for R = 1....N
=> (1 + 1)^N, using binomial theorem
=> 2^(n - 2)
*/
