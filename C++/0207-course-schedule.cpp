// Tags: DFS BFS Graph Topological-sort Amazon
// Topological sort using BFS
// Time: O(V+E)
// Space: O(V), without adjacency list
// Kahn's algorithm
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n,vector<int> ());
        vector<int> indegree(n,0);

        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for (int i=0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            n--;
            for (auto next: adj[cur])
                if (--indegree[next] == 0)
                    q.push(next);
        }
        return n==0;
    }
};
/*
Since we first decrement and then check if indegree == 0,
we will never push any node twice to our queue.

Prerequisites could be in format vector<pair<int, int>>& prerequisites.

Whenever we pop from queue, we add that elem to our topological ordering.
Here we are using the idea that if we are able to include all nodes in our
ordering, we have a topological order and hence no cycle
*/



// Time:  O(|V| + |E|)
// Space: O(|V|), without adjacency list
// DFS finding cycle
class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &visit, int u) {
        if (visit[u] == -1)
            return false;

        if (visit[u] == 1)
            return true;
        
        visit[u] = -1;
        
        for (int v : adj[u]) {
            if (!dfs(adj, visit, v))
                return false;
        }
        
        visit[u] = 1;
        
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses, vector<int>());
        vector<int> visit(numCourses, 0);
        
        for (const auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adj, visit, i))
                return false;
        }

        return true;
    }
};
