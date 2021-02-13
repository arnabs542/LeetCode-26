// Tags: DFS Union-find Amazon
// Time: O(n), where n = no of emails, we only visit each email once
// Space: O(n)
// Dfs solution
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // email to adjacent neighbours
        unordered_map<string, unordered_set<string>> adj;
        // (we know same email won't have different names)
        unordered_map<string, string> email2name;
        for (auto account: accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                email2name[account[i]] = name;
                if (i == 1)
                    continue;
                adj[account[i]].insert(account[i - 1]);
                adj[account[i - 1]].insert(account[i]);
            }
        }
        // visited emails
        unordered_set<string> visited;
        vector<vector<string>> res;
        for (auto kvp: email2name) {
            string email = kvp.first;
            string name = kvp.second;
            if (!visited.count(email)) {
                // list for the current name
                vector<string> cur {name};
                visited.insert(email);
                dfs(adj, visited, email, cur);
                sort(cur.begin() + 1, cur.end());
                res.push_back(cur);
            }
        }
        return res;
    }

private:
    void dfs(unordered_map<string, unordered_set<string>> &adj, unordered_set<string> &visited,
        string email, vector<string> &cur) {
        cur.push_back(email);
        for (string next: adj[email]) {
            if (!visited.count(next))  {
                visited.insert(next);
                dfs(adj, visited, next, cur);
            }
        }
    }
};

/*
Assume we have three accounts, we connect them like this in order to use DFS.
{Name, 1, 2, 3} => Name -- 1 -- 2 -- 3
{Name, 2, 4, 5} => Name -- 2 -- 4 -- 5 (The same graph node 2 appears)
{Name, 6, 7, 8} => Name -- 6 -- 7 -- 8
(Where numbers represent email addresses).
*/




struct UnionFind {
    unordered_map<string, string> parent;
    // initialize
    void add(string x) {
        if (parent.count(x))
            return;
        parent[x] = x;
    }
    string find(string x) {
        if (parent[x] == x)
            return parent[x];
        return parent[x] = find(parent[x]);
    }
    
    void Union(string u, string v) {
        add(u);
        add(v);
        string pu = find(u), pv = find(v);
        if (pu == pv)
            return;
        // further optimize by adding union by rank
        parent[min(pu, pv)] = max(pu, pv);
    }
};

// Time:  O(nlogn), n is the number of total emails, 
// or O(n) if we consider O(1) amortized cost for Union-find
// Space: O(n)
// Unionfind solution
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;
        unordered_map<string, string> email2name;
        for (auto account: accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                email2name[account[i]] = name;
                uf.Union(account[1], account[i]);
            }
        }
        unordered_map<string, set<string>> root2emails;
        for (const auto &kvp: email2name) {
            const auto &email = kvp.first;
            root2emails[uf.find(email)].insert(email);
        }
        vector<vector<string>> res;
        for (const auto &kvp: root2emails) {
            const auto &emails = kvp.second;
            vector<string> tmp {email2name[*emails.begin()]};
            for (const auto &email: emails)
                tmp.push_back(email);
            res.push_back(move(tmp));
        }
        return res;
    }
};
