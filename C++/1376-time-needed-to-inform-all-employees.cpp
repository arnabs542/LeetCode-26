// Tags: DFS Google
// Time: O(V + E) = O(n)
// Space: O(V + E) = O(n)
// Recursive solution
class Solution {
    int dfs(int u, vector<vector<int>>& adj, vector<int>& informTime) {
        int max_time = 0;
        for (int v : adj[u])
             max_time = max(max_time, dfs(v, adj, informTime));
        // informTime[u] == 0 if employee u has no subordinates.
        return max_time + informTime[u];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < manager.size(); ++i)
            if (i != headID)
                adj[manager[i]].push_back(i);
        return dfs(headID, adj, informTime);
    }
};



// Time:  O(n)
// Space: O(n)
// Iterative solution
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < manager.size(); ++i)
            if (i != headID)
                adj[manager[i]].push_back(i);
        stack<pair<int, int>> st;
        st.push({headID, 0});
        // maximum distance of any path from headID
        int res = 0;
        while (!st.empty()) {
            // cur is distance of current node from headID
            auto [node, cur] = st.top(); st.pop();
            cur += informTime[node];
            res = max(res, cur);
            for (int child : adj[node])
                st.push({child, cur});
        }
        return res;
    }
};
/*
Here, we just check how far any node can go from the root (headID).
*/
