// Tags: Segment-tree Amazon Greedy
// Time: O(n^2)
// Space: O(n)
// Bubble sort like solution, time limit exceeded
class Solution {
public:
    string minInteger(string num, int k) {
        if (k <= 0)
            return num;
        int n = num.length();
        if (k >= n*(n + 1)/2) {
            sort(num.begin(), num.end());
            return num;
        }
        // bring the minimum possible integer (0 ~ 9) to front
        // call minInteger for the remaining num string
        for (int i = 0; i < 10; ++i) {
            int idx = num.find('0' + i);
            // only k swaps available
            // (digit must be at index within k
            // from 0th index)
            if (idx >= 0 and idx <= k)
                return num[idx] + 
                    minInteger(num.substr(0, idx) + num.substr(idx + 1), k - idx);
        }
        return num;
    }
};




// Time: O(nlogn)
// Space: O(n)
// Using segment tree & list of queues
class SegmentTree {
    // tells count of numbers in the range
    vector<int> nodes;
    int n;
    void addUtil(int num, int low, int high, int pos) {
        if (num < low || num > high)
            return;
        if (low == high) {
            ++nodes[pos];
            return;
        }
        int mid = (low + high)/2;
        addUtil(num, low, mid, 2*pos + 1);
        addUtil(num, mid + 1, high, 2*pos + 2);
        nodes[pos] = nodes[2*pos + 1] + nodes[2*pos + 2];
    }

    int getUtil(int qlow, int qhigh, int low, int high, int pos) {
        if (qlow <= low && high <= qhigh)
            return nodes[pos];
        if (qhigh < low || qlow > high)
            return 0;
        int mid = (low + high)/2;
        return getUtil(qlow, qhigh, low, mid, 2*pos + 1) +
            getUtil(qlow, qhigh, mid + 1, high, 2*pos + 2);
    }

public:
    SegmentTree(int size) {
        nodes.resize(4*size);
        n = size;
    }
    // contruct tree element by element
    void add(int num) {
        addUtil(num, 0, n, 0);
    }
    // Essentialy it tells count of numbers < num
    int getCountLessThan(int num) {
        return getUtil(0, num, 0, n, 0);
    }
    
};

class Solution {
public:
    string minInteger(string num, int k) {
        // stores the location of each digit.
        vector<queue<int>> char2idx(10);
        for (int i = 0; i < num.length(); ++i)
            char2idx[num[i] - '0'].push(i);
        string res;
        SegmentTree seg(num.length());
        for (int i = 0; i < num.length(); ++i) {
            // At each location, try to place 0....9
            for (int d = 0; d <= 9; ++d) {
                // is there any occurrence of digit left?
                if(!char2idx[d].empty()) {
                    // yes, there is a occurrence of digit at pos
                    int idx = char2idx[d].front();
                    // Since few numbers already shifted to left, this `idx` might be outdated.
                    // we try to find how many number already got shifted that were to the left of idx.
                    int shift = seg.getCountLessThan(idx);
                    // (idx - shift) is number of steps to make digit move from idx to i.
                    if (idx - shift <= k) {
                        k -= idx - shift;
                        // add idx to our segment tree
                        seg.add(idx);
                        char2idx[d].pop();
                        res += d + '0';
                        break;
                    }
                }
            }
        }
        return res;
    }
};

/*
Observation 1: when we move a digit to left, only digits to the left of d
get their position shifted.
Observation 2: Choose first smallest d that is in reach of k.

For observation 1, to calculate the correct number of shifts, 
we will need to also store how many elements before d already shifted.
We will use segment tree for this (telling the count of numbers before a 
number).

For observation 2, We will use queue to choose latest occurence of each digit
*/
