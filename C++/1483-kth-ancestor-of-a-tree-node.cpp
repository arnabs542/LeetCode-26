// Tags: Google
/*
Brute force
Time: O(q*k), where q = number of queries

What if we remember all kth (1st, 2nd, 3rd, 4th.....) ancestors for each node?
Time: ctor: O(n*k^2), n = number of nodes
      getKthAncestor: O(1)
Still lead to TLE.
*/



// Time: ctor: O(log(max(k)) * n), where n = number of nodes, max(k) = n (one sided tree)
//       getKthAncestor: O(log(k))
// Space: O(log(max(k)) * n)
// Binary lifting / Jump pointers
class TreeAncestor {
    vector<vector<int>> up;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        // calculate log(n), maximum depth of tree if one sided,
        // maximum value of k
        while ((1 << LOG) <= n) {
            ++LOG;
        }
        // LOG = 16
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        
        // 2^0 = 1st ancestor
        for (int v = 0; v < n; ++v)
            up[v][0] = parent[v];
        
        
        // 2^i = 2, 4, 8, 16th ancestor
        for (int i = 1; i < LOG; ++i) {
            for (int v = 0; v < n; ++v) {
                // use k/2th ancestor of k/2th ancestor of v
                // to calculate kth ancestor of v, k = 2^i
                if (up[v][i - 1] != -1)
                    up[v][i] = up[up[v][i - 1]][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // if k = 19
        // => 10011 = 16 + 2 + 1 = 16th ancestor of 2nd ancestor of 1st ancestor of node
        for (int i = 0; i < LOG; ++i) {
            // ith bit is set
            if (k & (1 << i)) {
                // next ancestor to look
                node = up[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
/*
We need a much more efficient way to prepare and get data. When we want to get kth ancestor
of [node], if we have already known k/2th ancestor, we can use k/2th parent twice to get
the answer.

Let's remember only 2^ith parent of every node.
We can get node u's 5th parent by tracing node v's 4th parent, where node v is 1st parent
of node u.

Let up[u][i] represent node u's 2^ith ancestor. Now, when we want to get kth parent, we just turn
the number 'k' into binary and check the set bits to trace parent.

Preparing data:
for v = 0.....n - 1
up[v][0] = parent[v]
up[v][1] = up[ up[v][0] ][0]
up[v][2] = up[ up[v][1] ][1]
up[v][3] = up[ up[v][2] ][2]
....
*/
