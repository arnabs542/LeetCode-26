// Tags: Amazon Premium String Tree
// Time: O(n^2)
// Space: O(n)
class Solution {
    list<Node*> op(const list<Node*> &l, char op1, char op2) {
        list<Node*> l1;
        for (auto it = l.begin(); it != l.end(); ++it) {
            // get Node* (operator node)
            auto o = *it;
            // only consider individual nodes (operator nodes) and
            // skip nodes/subtrees returned by (...) or previous op(l, '*', '/');
            // (we are sure that nodes either have 0 or 2 children)
            if (o->left == nullptr && (o->val == op1 || o->val == op2)) {
                // if either of the two operators
                o->left = l1.back();
                o->right = *next(it);
                // replace last node with this subtree
                l1.back() = o;
                // skip the very next node;
                ++it;
            } else {
                l1.push_back(o);
            }
        }
        // returns simplified list
        // (list contains only 1 Node* after the two calls)
        return l1;
    }
public:
    Node* expTree(string s) {
        list<Node *> l;
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                int j = i + 1;
                // find matching ')'
                for (int bal = 1; bal > 0; ++j)
                    bal += s[j] == ')' ? -1 : s[j] == '(' ? 1 : 0;
                l.push_back(expTree(s.substr(i + 1, j - i - 2)));
                // j is 1 ahead of where ')' is found
                // (decrement it so that at the end of loop it is
                // incremented back to j)
                i = j - 1;
            } else {
                l.push_back(new Node(s[i]));
            }
        }
        return op(op(l, '*', '/'), '+', '-').front();
    }
};
/*
* Conversion with recursion, O(n^2):
  Convert all characters into nodes and store them in list l.
  Recursion: if we detect a group (...), call expTree recursively and insert the returned tree root into l.
* Pass 1 for elements in l, O(n):
  For * and / leaf nodes, 'adopt' left and right neighbors to be its children (neighbors are removed from
  the list).
* Pass 2 for the remaining elements in l, O(n):
  Do the same as in pass 1 for + and - leaf nodes.
After this, we should have one element remaining in l - our root node
*/



// Time: O(n)
// Space: O(n)
// Efficient stack based solution
// (conversion time reduced from O(n^2) to O(n))
class Solution {
    list<Node*> op(const list<Node*> &l, char op1, char op2) {
        list<Node*> l1;
        for (auto it = l.begin(); it != l.end(); ++it) {
            // get Node*
            auto o = *it;
            // only consider individual nodes and
            // skip nodes/subtrees returned by (...) or previous op(l, '*', '/');
            // (we are sure that nodes either have 0 or 2 children)
            if (o->left == nullptr && (o->val == op1 || o->val == op2)) {
                // if either of the two operators
                o->left = l1.back();
                o->right = *next(it);
                // replace last node with this subtree
                l1.back() = o;
                // skip the very next node;
                ++it;
            } else {
                l1.push_back(o);
            }
        }
        return l1;
    }
public:
    Node* expTree(string s) {
        // stack of lists having a list for each (....)
        vector<list<Node*>> st(1);
        for (auto i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push_back(list<Node*>());
            } else if (s[i] == ')') {
                // processing a (....)
                auto root = op(op(st.back(), '*', '/'), '+', '-').front();
                st.pop_back();
                // adding root to previous list
                st.back().push_back(root);
            } else {
                st.back().push_back(new Node(s[i]));
            }
        }
        // finally only 1 list in the stack
        return op(op(st.back(), '*', '/'), '+', '-').front();
    }
};
