// Tags: Tree Amazon
// Time: O(m*n), m is the number of nodes of s, n is the number of nodes of t
// Space: O(h), h is the height of s
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return preOrderTraverse(s, t);

    }

private:
    bool isSame(TreeNode *x, TreeNode *y){
        if (!x && !y)
            return true;

        if (!x || !y)
            return false;

        return x->val == y->val && isSame(x->left, y->left) && isSame(x->right, y->right);
    }

    bool preOrderTraverse(TreeNode *s, TreeNode *t) {
        return s && (isSame(s, t) || preOrderTraverse(s->left, t) || preOrderTraverse(s->right, t));
    }
};




class Solution {
    bool isSame(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return s && (isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};

