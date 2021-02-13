// Tags: Tree Amazon
// Time: O(n) ~ O(n^2), at each node, creation of serial
// may take O(n), string concatenation
// Space: O(n) ~ O(n^2), due to count
class Solution {
    string postOrderTraversal(TreeNode* node, unordered_map<string, int> *count,
        vector<TreeNode*> *res) {
        if (!node)
            return "#";
        // serial string
        string s = to_string(node->val) + ",";
        s += postOrderTraversal(node->left, count, res) + ",";
        s += postOrderTraversal(node->right, count, res);
        ++(*count)[s];
        if ((*count)[s] == 2)
            res->push_back(node);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> count;
        vector<TreeNode*> res;
        postOrderTraversal(root, &count, &res);
        return res;
    }
};

/*
If we consider combining of left and right subtrees' unique idetifier
strings takes O(1) time, then time complexity is O(n) as we traverse
tree only once in postorder fashion.
However, in actual, say for the root node,
    s.length() = 1 + 1 + n/2 + 1 + n/2 = O(n) as concatenation takes linear
    time
*/



// Time: O(n)
// Space: O(n)
class Solution {
    int t;
    int postOrderTraversal(TreeNode* node, unordered_map<int, int> *count,
        vector<TreeNode*> *res, unordered_map<string, int> &s2id) {
        if (!node)
            return 0;
        string s = to_string(node->val) + ",";
        s += to_string(postOrderTraversal(node->left, count, res, s2id)) + ",";
        s += to_string(postOrderTraversal(node->right, count, res, s2id));
        int uid;
        if (s2id.count(s))
            uid = s2id[s];
        else {
            uid = t++;
            s2id[s] = uid;
        }
        ++(*count)[uid];
        if ((*count)[uid] == 2)
            res->push_back(node);
        return uid;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // uid to count
        unordered_map<int, int> count;
        vector<TreeNode*> res;
        // serial to uid
        unordered_map<string, int> s2id;
        t = 1;
        postOrderTraversal(root, &count, &res, s2id);
        return res;
    }
};
/*
We can improve this to O(n) by replacing full serializations with
serial ids instead. Now each s.length() == 5.
*/
