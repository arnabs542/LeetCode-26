// Topological Sort using BFS
// Time: O(V+E)
// Space: O(V)
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

/* Notes:
Since we first decrement and then check if indegree == 0,
we will never push each node twice to our queue
Prerequisites could be in format vector<pair<int, int>>& prerequisites*/
