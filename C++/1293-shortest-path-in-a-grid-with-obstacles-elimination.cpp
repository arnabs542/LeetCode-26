// Tags: BFS Amazon
// Time: O(m*n*k)
// Space: O(m*n*k)
// for every cell (m*n), in the worst case we have to put that 
// cell into the queue/bfs k times.
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 and n == 1)
            return 0;
        // -2 because grid[0][] = grid[m - 1][n - 1] = 0
        if (k > m - 1 + n - 1)
            return m + n - 2;
        // row, col, eliminate left, steps
        queue<tuple<int, int, int, int>> q;
        unordered_set<string> visited;
        visited.insert("0$0#" + to_string(k));
        vector<pair<int, int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        q.push({0, 0, k, 0});
        while (!q.empty()) {
            auto [row, col, eliminate, steps] = q.front(); q.pop();
            for (auto d: dirs) {
                int nrow = row + d.first, ncol = col + d.second;
                if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n)
                    continue;
                string prefix = to_string(nrow) + "$" + to_string(ncol) + "#";
                // 1. check if eligible edge i.e eliminate > 0.
                // 2. if there was already an eligible edge with same eliminate usage,
                //    skip this edge. (this is because if we are visiting the same 
                //    cell again it obviously has either same or larger steps values
                //    (due to BFS structure)
                // (ideally we should check if larger eliminate value), not sure
                if (grid[nrow][ncol] == 1 && eliminate > 0 && 
                    !visited.count(prefix + to_string(eliminate - 1))) {
                    visited.insert(prefix + to_string(eliminate - 1));
                    q.push({nrow, ncol, eliminate - 1, steps + 1});
                }
                if (grid[nrow][ncol] == 0 && !visited.count(prefix + to_string(eliminate))) {
                    if (nrow == m - 1 && ncol == n - 1)
                        return steps + 1;
                    visited.insert(prefix + to_string(eliminate));
                    q.push({nrow, ncol, eliminate, steps + 1});
                }
            }
            
        }
       return - 1; 
    }
    
};

/*
Why not Dijkstra?
Like 0787-cheapest-flights-within-k-stops, we are asked to return the
shortest path from source to destination having atmost k obstacles.
So, we can use Dijkstra here.
However, since all path-costs are same here (1 for each hop), we can
safely replace Dijkstra with BFS. This way the logic can be simplified
to see that if we visit (i, j) again, we allow it as long as the 
eliminate usage count is less than k.
*/

/*
Because we are trying to find the shortest path, use BFS here to 
exit immediately when a path reaches the bottom right most cell.
(with shortest eligible path having obstacle eliminate usage less 
than k)

Use a set to keep track of already visited paths. We only need to 
keep track of the row, column, and the eliminate obstacle usage
count. We don't need to keep track of the steps because remember
we are using BFS for the shortest path. That means there is no value
storing a 4th piece of the data, the current steps. This will reduce
the amount of repeat work.

Note: We push multiple copies of same cell into queue with different
      different available eliminate values and possibly different
      steps value.
*/
