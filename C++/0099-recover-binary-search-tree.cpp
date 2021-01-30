// Tags: Amazon Tree
// Time: O(n)
// Space: O(n)
// Naive solution, Sort an almost sorted array where two elements are swapped
class Solution {
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    // finds two swapped elements in an almost sorted array
    pair<int, int> findTwoSwapped(vector<int>& nums) {
        int x = -1, y = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                if (x == -1) {
                    // first swap occurence
                    x = nums[i];
                    // (candidate for being y)
                    y = nums[i + 1];
                } else {
                    // second swap occurence (if exists)
                    y = nums[i + 1];
                    break;
                }
            }
        }
        return {x, y};
    }
    void recover(TreeNode* root, int count, int x, int y) {
        // normal preorder traversal
        if (!root)
            return;
        if (root->val == x || root->val == y) {
            root->val = (root->val == x) ? y : x;
            if (--count == 0)
                return;
        }
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        auto [x, y] = findTwoSwapped(nums);
        recover(root, 2, x, y);
    }
};
/*
 Do inorder traversal (almost sorted array), find the two swapped elements
 then traverse tree again and swap values of those two nodes
*/



// Time: O(n) in worst case when one of swapped nodes is rightmost leaf
// Space: O(n), to keep stack in worst case when tree is
// completely lean, O(logn) if balanced tree
// Reusing 0098-validate-binary-search-tree & findTwoSwapped()
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr, *cur = root;
        stack<TreeNode*> st;
        // predecessor of current node in inorder traversal
        TreeNode *pred = nullptr;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                if (pred && cur->val < pred->val) {
                    // i+1 th
                    y = cur;
                    if (x == nullptr)
                        x = pred; // ith
                    else
                        break;
                }
                // update pred
                pred = cur;
                // move to right branch
                cur = cur->right;
            }
        }
        // swap values
        int tmp = y->val;
        y->val = x->val;
        x->val = tmp;
    }
};



// Time: O(n)
// Space: O(1)
// Morris inorder traversal
class Solution {
    // not being used currently
    void findBroken(TreeNode* pred, TreeNode* cur, TreeNode* x, TreeNode* y) {
        if (pred && pred->val > cur->val) {
            y = cur;
            if (x == nullptr)
                x = pred;
        }
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *x = nullptr, *y = nullptr;
        TreeNode *cur = root, *pred = nullptr;
        while (cur) {
            if (cur->left) {
                TreeNode *tpred = cur->left;
                while (tpred->right != cur && tpred->right)
                    tpred = tpred->right;
                if (!tpred->right) {
                    tpred->right = cur;
                    cur = cur->left;
                } else {
                    tpred->right = nullptr;
                    
                    // visit
                    if (pred && cur->val < pred->val) {
                        y = cur;
                        if (x == nullptr)
                            x = pred;
                    }
                    pred = cur;
    
                    cur = cur->right;
                }
            } else {
                // visit
                if (pred && cur->val < pred->val) {
                        y = cur;
                        if (x == nullptr)
                            x = pred;
                }
                pred = cur;
                
                cur = cur->right;
            }
        }
        swap(x->val, y->val);
    }
};
