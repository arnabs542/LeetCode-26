// Tags: Union-find Math WC211
// Failed attempt: stack-overflow as graph has cycles which causes
// recursive call to already visited ancestor node
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (common(i + 1, j + 1) > threshold) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // int i = 0;
        // for (auto &a: adj) {
        //     cout << i;
        //     for (auto &b: a) {
        //         cout << b;
        //     }
        //     cout << endl;
        //     ++i;
        vector<bool> res;
        for (auto &query: queries) {
            if (dfs(query[0] - 1, -1, query[1] - 1, adj))
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }

    int common(int a, int b) {
        int x = min(a, b);
        int y = max(a, b);
        int res = 1;
        for (int i = 2; i <= x; i++) {
            if (x%i == 0 && y%i == 0)
                res = i;
        }
        return res;
    }

    bool dfs(int src, int parent, int dest, vector<vector<int>> &graph) {
        if (src == dest)
            return true;
        if (graph[src].empty())
            return false;
        for (auto &child: graph[src]) {
            if (child == parent)
                continue;
            if (dfs(child, src, dest, graph))
                return true;
        }
        return false;
    }
};




// Time: O(n + m), where m is the number of queries
// Union Find method
// Space: O(n) for the disjoint set
class UnionFind {
  vector<int> parent, size;
public:
  UnionFind(int n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i; // self loop
      size[i] = 1; // only 1 elem
    }

    int find(int x) {
      if(x == parent[x])
        return x;
      return parent[x] = find(parent[x]); // path compression
    }

    bool Union(int u, int v) {
      int pu = find(u), pv = find(v);
      if (pu == pv) return false; // already merged
      if (size[pu] > size[pv]) {
        size[pu] += size[pv];
        parent[pv] = pu;
      } else {
        size[pv] += size[pu];
        parent[pu] = pv;
      }
      return true;
    }
  }
}

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries)
    {
        UnionFind uf(n+1);
        // building graph
        for (int i = 1; i <= n; ++i) {
            // all multiples of i starting from 2nd multiple
            for (int j = i*2; j <= n; j += i) {
                if (i > threshold)
                    uf.Union(i, j);
            }
        }
        vector<bool> res;
        for (auto &q: queries) {
            int pa = uf.find(q[0]);
            int pb = uf.find(q[1]);
            res.push_back(pa == pb);
        }
        return res;
    }
};

/*
Building graph:
Key idea to understand is that any integer node a will be
connected to all the multiples of a provided that a is
greater than the threshold.

Time Complexity (to understand):
O(m) is to answer all the queries. The 'find' operation in union-find
takes a constant time since we are using the path compression.
At this point, the tree is compressed as we do not do any joints anymore.

O(n) to build the disjoint set. This one could be a bit tricky.
First, we assume that each operation in union-find takes a constant time.
This is because we use both the ranking and path compression, giving us O(𝛼(n)).
The inverse Ackermann function (𝛼) can be considered a constant for all practical purposes.
1.  When building the disjoint set, we are only processing nodes that were not previously
    connected. When our smallest factor is 1, we would add each node to a single group - O(n).
2.  If our smallest factor is 2, we will have n * (1 / 2 + 1 / 3 + 1 / 5 + ... 1/𝑝) total
    operations, where 𝑝 is a prime <= n / 2. The sum Σ1/𝑝 over primes 𝑝 <= n is asymptotic to
    ln ln n. This number is 2 if n = 4000, and 3 if n = INT_MAX. So we can consider it as a
    constant for practical purposes.
3.  If our smallest factor is greater than 2, the number of operations will be < ln ln n.
*/
