// Tags: D&C BST BIT Segment-tree Sort Top-interview
// Time:  O(nlogn)
// Space: O(n)
// Divide and Conquer solution
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size());
        // integer, index pairs (we need the indices in the original array
        // to update the result array count)
        vector<pair<int, int>> numIdx;
        for (auto i = 0; i < nums.size(); ++i)
            numIdx.emplace_back(nums[i], i);
        mergeSort(numIdx, count, 0, numIdx.size() - 1);
        return count;
    }
    
    void mergeSort(vector<pair<int, int>> &numIdx, vector<int> &count, int lo, int hi) {
        if (lo >= hi)
            return;
        int mid = lo + (hi - lo)/2;
        mergeSort(numIdx, count, lo, mid);
        mergeSort(numIdx, count, mid + 1, hi);
        merge(numIdx, count, lo, mid, hi);
    }
    
    void merge(vector<pair<int, int>> &numIdx, vector<int> &count, int lo, int mid, int hi) {
        vector<pair<int, int>> tmp (hi - lo + 1);
        // indices: left sorted array, right sorted array, combined sorted array
        int i = lo, j = mid + 1, k = 0;
        
        // the number of elements in the right sorted part that are smaller than
        // the next element from the left sorted part
        int rightCount = 0;
        while (i <= mid && j <= hi) {
            if (numIdx[j].first < numIdx[i].first) {
                // increment rightCount when numbers from right jump to combined array
                // (preparing rightCount for the next element from left to move to
                // combined array)
                ++rightCount;
                tmp[k++] = numIdx[j++];
            } else {
                // add the current rightCount
                count[numIdx[i].second] += rightCount;
                tmp[k++] = numIdx[i++];
            }
        }
        while (j <= hi) {
            tmp[k++] = numIdx[j++];
        }
        while (i <= mid) {
            count[numIdx[i].second] += rightCount;
            tmp[k++] = numIdx[i++];
        }
        copy(tmp.begin(), tmp.end(), numIdx.begin() + lo);
    }
};

/*
The smaller numbers on the right of a number are exactly those that jump
from its right to its left during a stable sort. So we do mergesort with
added tracking of those right-to-left jumps.
*/



// Time:  O(nlogn) ~ O(n^2) 
// (Balanced Tree ~ One-sided linked list)
// Space: O(n)
// Binary Search Tree solution
class Solution {
    class TreeNode {
        public:
        // value, number of nodes in the left subtree
        int val, smallerCnt;
        TreeNode *left, *right;
        TreeNode (int v, int s): left(nullptr), right(nullptr), val(v), smallerCnt(s) {
            
        }
    };
    // preSum : the number of nodes smaller than the node being added
    TreeNode* insert(vector<int> &res, int val, int idx, int preSum, TreeNode* node) {
        if (!node) {
            // create & insert node here
            // note that s is 0 in the node constructor
            node = new TreeNode(val, 0);
            res[idx] = preSum;
        } else if (node->val > val) {
            // when we go left we increment the smallerCnt values of the nodes on the way
            ++node->smallerCnt;
            // assign the created node to the left point of current node
            node->left = insert(res, val, idx, preSum, node->left);
        } else {
            // val greater than or equal to node->val
            // when we go right we keep adding the smallerCnt values of the nodes on the way to preSum + 1
            node->right = insert(res, val, idx, preSum + node->smallerCnt + ((node->val < val)? 1: 0), node->right);
        }
        return node;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return vector<int>();
        vector<int> res(n);
        TreeNode* root {nullptr};
        for (int i = n - 1; i >= 0; --i)
            root = insert(res, nums[i], i, 0, root);
        return res;
    }
};


// To do: Binary Indexed Tree solution
