// Tags: Top-interview Premium Graph Topological-sort
// Time:  O(n), n be the total length of all the words
// in the input list, added together
// Space: O(|V|+|E|) = O(26 + 26^2) = O(1)
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
