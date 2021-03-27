// Tags: Amazon Premium DFS BFS
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// Time: O(n), n = total number of nested elements in the input list
// eg. [ [[[[1]]]], 2 ] contains 4 nested lists and 2 nested integers, so n = 6
// Space: O(d), d = maximum level of nesting, d = 4 in above example
// in worst case, d = n, eg. [[[[[[]]]]]]
// Dfs
class Solution {
    int dfs(vector<NestedInteger>& nested_list, int depth) {
        int total = 0;
        for (NestedInteger nested: nested_list) {
            if (nested.isInteger()) {
                total += nested.getInteger()*depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};



// Time: O(n), n = total number of nested elements in the input list
// Space: O(d), d = max number of elements at any level, which is n in worst case
// eg. [1, 2, 3, 4, 5]
// Bfs
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;
        for (NestedInteger nested: nestedList)
            q.push(nested);
        int depth = 1;
        int total = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                NestedInteger nested = q.front(); q.pop();
                if (nested.isInteger()) {
                    total += nested.getInteger() * depth;
                } else {
                    for (NestedInteger next_nested: nested.getList())
                        q.push(next_nested);
                }
            }
            ++depth;
        }
        return total;
    }
};
