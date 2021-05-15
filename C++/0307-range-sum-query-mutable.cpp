// Tags: Segment-tree Binary-indexed-tree 
/* 
Brute force
Time: ctor: O(1)
      update: O(1)
      sumRange: O(n)
Space: O(1)

2D table (worse than brute force)
Time: ctor: O(n^2)
      update: O(n^2)
      sumRange: O(1)
Space: O(n^2)

Prefix sum
Time: ctor: O(n)
      update: O(n)
      sumRange: O(1)
Space: O(1), modifying the input array
*/



// Time:  ctor: O(n),
//        update: O(logn),
//        query: O(logn)
// Space: O(n)
// Segment tree solution (Representing segment tree using nodes)
class SegTreeNode {
public:
    int start, end;
    int sum;
    SegTreeNode *left, *right;
    SegTreeNode(int i, int j, int s): start(i),
        end(j), sum(s), left(nullptr), right(nullptr) {
        }
};
class NumArray {
    vector<int> nums;
    SegTreeNode *root;
    // construct
    SegTreeNode* buildHelper(int start, int end) {
        if (start > end)
            return nullptr;
        // create a node for the current interval [start, end]
        SegTreeNode* root = new SegTreeNode(start, end, 0);
        
        if (start == end) {
            // there will be no children for this node
            root->sum = nums[start];
            return root;
        }
        
        int mid = (start + end) / 2;
        // left child having interval [start, mid]
        root->left = buildHelper(start, mid);
        // right child having interval [mid + 1, end]
        root->right = buildHelper(mid + 1, end);
        
        // update sum
        root->sum = (root->left != nullptr ? root->left->sum : 0) +
            (root->right != nullptr ? root->right->sum : 0);
        return root;
    }
    
    // update leaf node and then propage the result upwards
    void updateHelper(SegTreeNode* root, int i, int val) {
        if (root == nullptr || i < root->start || root->end < i) {
            // out of range
            return;
        }
        if (root->start == i && root->end == i) {
            // update node's value to the new val
            root->sum = val;
            return;
        }
        // i present somewhere in the middle of range
        // [root->start root->end]
        updateHelper(root->left, i, val);
        updateHelper(root->right, i, val);
        // update sum
        root->sum = (root->left != nullptr ? root->left->sum : 0) +
            (root->right != nullptr ? root->right->sum : 0);
    }
    
    // query
    int sumRangeHelper(SegTreeNode* root, int qstart, int qend) {
        if (root == nullptr || qend < root->start || root->end < qstart) {
            // out of range
            // (no overlap)
            return 0;
        }
        
        if (qstart <= root->start && root->end <= qend) {
            // current segment/interval is totally within range [start, end]
            // (total overlap)
            return root->sum;
        }
        // (partial overlap)
        // look into both branches and add
        return sumRangeHelper(root->left, qstart, qend) +
            sumRangeHelper(root->right, qstart, qend);
    }
public:
    NumArray(vector<int>& nums): nums(nums) {
        root = buildHelper(0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        if (nums[index] != val) {
            // value is changed
            nums[index] = val;
            updateHelper(root, index, val);
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(root, left, right);
    }
};



// Time:  ctor: O(n),
//        update: O(logn),
//        query: O(logn)
// Space: O(n)
// Segment tree solution (Representing segment tree using an array)
class NumArray {
    vector<int> nums;
    vector<int> seg_tree;
    // construct
    void buildHelper(int start, int end, int pos) {
        if (start == end) {
            seg_tree[pos] = nums[start];
            return;
        }
        
        int mid = (start + end) / 2;
        buildHelper(start, mid, 2*pos + 1);
        buildHelper(mid + 1, end, 2*pos + 2);
        
        seg_tree[pos] = seg_tree[2*pos + 1] + seg_tree[2*pos + 2];
    }
    
    // update
    void updateHelper(int i, int val, int start, int end, int pos) {
        if (i < start || end < i) {
            return;
        }
        if (start == i && end == i) {
            seg_tree[pos] = val;
            return;
        }
        int mid = (start + end) / 2;
        updateHelper(i, val, start, mid, 2*pos + 1);
        updateHelper(i, val, mid + 1, end, 2*pos + 2);
        
        seg_tree[pos] = seg_tree[2*pos + 1] + seg_tree[2*pos + 2];
    }
    
    // query
    int sumRangeHelper(int qstart, int qend, int start, int end, int pos) {
        if (qend < start || end < qstart) {
            return 0;
        }
        
        if (qstart <= start && end <= qend) {
            return seg_tree[pos];
        }
        int mid = (start + end) / 2;
        return sumRangeHelper(qstart, qend, start, mid, 2*pos + 1) +
            sumRangeHelper(qstart, qend, mid + 1, end, 2*pos + 2);
    }
public:
    NumArray(vector<int>& nums): nums(nums) {
        seg_tree.resize(4*nums.size());
        buildHelper(0, nums.size() - 1, 0);
    }
    
    void update(int index, int val) {
        if (nums[index] != val) {
            nums[index] = val;
            updateHelper(index, val, 0, nums.size() - 1, 0);
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(left, right, 0, nums.size() - 1, 0);
    }
};
