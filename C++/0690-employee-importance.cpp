// Tags: DFS BFS Hash-table Google
// Time: O(n)
// Space: O(h)
// Dfs solution
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
    int dfs(unordered_map<int, Employee*>& employees, int id) {
        auto result = employees[id]->importance;
        for (const auto& sid: employees[id]->subordinates) {
            result += dfs(employees, sid);
        }
        return result;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp_map;
        for (auto emp : employees)
            emp_map.insert({emp->id, emp});
        return dfs(emp_map, id);
    }
};



// Time:  O(n)
// Space: O(w), w is the max number of nodes in any level of tree
// Dfs
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp_map;
        for (auto emp : employees)
            emp_map.insert({emp->id, emp});
        queue<int> q;
        q.push(id);
        int res = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += emp_map[u]->importance;
            for (auto sid: emp_map[u]->subordinates)
                q.push(sid);
        }
        return res;
    }
};
