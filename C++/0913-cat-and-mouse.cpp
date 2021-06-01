// Tags: Minimax DFS Google
// Time: O(n^2 * n * log(n)), can get rid of log easily by changing map to array
// Space: O(n^2)
const int MOUSE = 1, CAT = 2;
using State = tuple<int, int, int>;
// key: cat position, mouse position, turn
// value: true if winning vertex else false
map<State, bool> winning;
// number of outgoing edges that lead to winning vertex
map<State, int> outdegree;
// adj_rev if graph was directed
vector<vector<int>> adj;
vector<int> cat_degree;
class Solution {
    bool defined(State state) {
        auto [cat, mouse, turn] = state;
        return cat == mouse || mouse == 0;
    }
    void dfs(State state, bool result) {
        if (winning.count(state))
            return;
        winning[state] = result;
        auto [cat, mouse, turn] = state;
        if (turn == MOUSE) {
            // CAT moved from prev_cat to cat
            for (int prev_cat : adj[cat]) {
                State prev_state{prev_cat, mouse, CAT};
                if (defined(prev_state) || prev_cat == 0)
                    continue;
                if (!result) {
                    // if I am losing vertex, prev undefined vertex is winning one
                    dfs(prev_state, true);
                } else {
                    // if I am winning vertex, prev underfined vertex is losing one in case
                    // all its outgoing edges lead to winning vertices
                    if (++outdegree[prev_state] == cat_degree[prev_cat]) {
                        dfs(prev_state, false);
                    }
                }
            }
        } else {
            // MOUSE moved from prev_mouse to mouse
            for (int prev_mouse : adj[mouse]) {
                State prev_state{cat, prev_mouse, MOUSE};
                if (defined(prev_state))
                    continue;
                if (!result) {
                    dfs(prev_state, true);
                } else {
                    if (++outdegree[prev_state] == (int) adj[prev_mouse].size()) {
                        dfs(prev_state, false);
                    }
                }
            }
        }
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        // important to clear global data structures
        winning.clear();
        outdegree.clear();
        adj = graph;
        int n = graph.size();
        // adj[prev_cat].size() won't give the right number of outgoing edges
        // in dfs if one of adjacent vertex is 0 (which is prohibited)
        cat_degree = vector<int>(n);
        for (int u = 0; u < n; ++u) {
            cat_degree[u] = adj[u].size();
            for (int v : adj[u]) {
                if (v == 0)
                    --cat_degree[u];
            }
        }
        for (int cat = 1; cat < n; ++cat) {
            for (int turn : {CAT, MOUSE}) {
                if (turn == CAT) {
                    // winning vertex
                    dfs({cat, cat, turn}, true);
                    // losing vertex
                    dfs({cat, 0, turn}, false);
                } else {
                    // losing vertex
                    dfs({cat, cat, turn}, false);
                    // winning vertex
                    dfs({cat, 0, turn}, true);
                }
            }
        }
        State start{2, 1, MOUSE};
        if (winning.count(start)) {
            if (winning[start])
                return 1;
            else
                return 2;
        }
        return 0;
    }
};
