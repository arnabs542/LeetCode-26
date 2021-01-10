// Tags: Top-interview Premium Graph Topological-sort Amazon
// Time:  O(n), n be the total length of all the words
// in the input list, added together
// Space: O(|V|+|E|) = O(26 + 26^2) = O(1)
// Using BFS (Kahn's algorithm)
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        
        // initialize
        for (auto i = 0; i < words.size(); ++i)
            for (auto j = 0; j < words[i].size(); ++j) {
                char c = words[i][j];
                indegree[c] = 0;
            }
        
        // build graph and record indegree
        for (auto i = 0; i < words.size() - 1; ++i) {
            string cur = words[i];
            string nex = words[i + 1];
            for (int j = 0; j < min(cur.size(), nex.size()); ++j) {
                if (cur[j] != nex[j]) {
                    if (!graph[cur[j]].count(nex[j])) {
                        graph[cur[j]].insert(nex[j]);
                        ++indegree[nex[j]];
                    }
                    break;
                }
                // Check that nex is not a prefix of cur 
                // (invalid input as in valid alphabet, prefix always comes first)
                if (j == nex.size() - 1 && cur.size() > nex.size())
                    return "";
            }
        }
        
        queue<char> q;
        string res;
        for (auto &n: indegree)
            if (n.second == 0)
                q.push(n.first);
        
        while (!q.empty()) {
            char cur = q.front(); q.pop();
            res += cur;
            for (auto &n: graph[cur]) {
                if (--indegree[n] == 0)
                    q.push(n);
            }
        }
        return res.length() == indegree.size() ? res : "";
    }
};



// Time:  O(n), n be the total length of all the words
// in the input list, added together
// Space: O(|V|+|E|) = O(26 + 26^2) = O(1)
// Using DFS (finding cycle)
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 26 characters
        unordered_map<char, unordered_set<char>> graph;
        // 26 characters
        vector<int> visit(26, -2);
        
        // initialize
        for (auto i = 0; i < words.size(); ++i)
            for (auto j = 0; j < words[i].size(); ++j) {
                char c = words[i][j];
                visit[c - 'a'] = 0;
        }
        
        // build graph and record indegree
        for (auto i = 0; i < words.size() - 1; ++i) {
            string cur = words[i];
            string nex = words[i + 1];
            for (int j = 0; j < min(cur.size(), nex.size()); ++j) {
                if (cur[j] != nex[j]) {
                    if (!graph[cur[j]].count(nex[j])) {
                        graph[cur[j]].insert(nex[j]);
                    }
                    break;
                }
                // Check that nex is not a prefix of cur 
                // (invalid input as in valid alphabet, prefix always comes first)
                if (j == nex.size() - 1 && cur.size() > nex.size())
                    return "";
            }
        }
        string res;
        function<bool(char)> dfs = [&] (char u) {
            if (visit[u - 'a'] == -1)
                return false;
            if (visit[u - 'a'] == 1)
                return true;
            visit[u - 'a'] = -1;
            for (auto v: graph[u])
                if (!dfs(v))
                    return false;
            res += u;
            visit[u - 'a'] = 1;
            return true;
        };
        
        for (int i = 0; i < 26; ++i)
            if (visit[i] == 0)
                if (!dfs('a' + i))
                    return "";
        
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
A topological ordering is possible if and only if the graph has no directed cycles

States:
visit[i] = -2. Not even exist.
visit[i] = 0. Exist. Non-visited.
visit[i] = -1. Visiting.
visit[i] = 1. Visited.
*/
