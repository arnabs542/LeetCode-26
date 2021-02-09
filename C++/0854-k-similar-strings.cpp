// Tags: Graph BFS Amazon
// Time:  O(n * n!/(c_a!*...*c_f!), n is the length of A, B,
//                                  c_a...c_f is the count of each alphabet,
//                                  n = sum(c_a...c_f)
// (the given string can be arranged in n!/(c_a!*...*c_f!) ways, at max we would
// try each of those arrangements at each level)
// Space: O(n * n!/(c_a!*...*c_f!)
// where n!/(c_a!*...*c_f! is the number of ways string A can be arranged
// BFS templace 1.0
class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A == B)
            return 0;
        queue<string> q;
        unordered_set<string> visited;
        int result = 0;
        q.push(A);
        visited.insert(A);
        while (!q.empty()) {
            // current level
            for (int sz = q.size() - 1; sz >= 0; --sz) {
                string s = q.front(); q.pop();
                if (s == B)
                    return result;
                int i;
                // skip already sorted characters
                for (i = 0; s[i] == B[i]; ++i);
                // try each eligible swap with s[i]
                for (int j = i + 1; j < s.length(); ++j) {
                    // jth char is correct or jth char is not the
                    // target value of ith char, swapping would be
                    // meaningless
                    if (s[j] == B[j] || s[j] != B[i])
                        continue;
                    swap(s[i], s[j]);
                    if (!visited.count(s)) {
                        visited.insert(s);
                        q.push(s);
                    }
                    // return string to original state
                    swap(s[i], s[j]);
                }
            }
            ++result;
        }
        return result;
    }
};
/*
When it comes to shorted step, we should always have Bfs in mind.

Here we only swap the i-th and j-th character when j-th character is
wrong and it happends to be the target character of i-th position.

So that in each round we will repair the first unordered character
(ith char) and as a result move forward at least 1 step.

Note:
We could also do Bfs like in 0909-snakes-and-ladders (a little faster
as we don't have to go through all level completely)
*/
