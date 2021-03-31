// Tags: DFS BFS Graph Amazon
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// Time: O(V + E), E could be O(V^2) in case of dense graph
// Space: O(V + E)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> cloned;
        Node* cnode = new Node(node->val);
        cloned[node] = cnode;
        stack<Node*> st;
        st.push(node);
        while (!st.empty()) {
            Node *cur = st.top(); st.pop();
            for (Node* neighbor : cur->neighbors) {
                if (!cloned.count(neighbor)) {
                    // ensure each node is visited only once
                    // (mark it visited)
                    cloned[neighbor] = new Node(neighbor->val);
                    st.push(neighbor);
                }
                cloned[cur]->neighbors.push_back(cloned[neighbor]);
            }
        }
        return cnode;
    }
};
/*
cloned Map contains visited and to be visited ie stack nodes

In dfs, we don't want to push the nodes which are either already
visited or in stack currently.
*/
