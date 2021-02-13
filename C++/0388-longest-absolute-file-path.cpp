// Tags: Amazon
// Time: O(n)
// Space: O(d), d is the max depth of the paths
class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
        string cur;
        int res = 0;
        // records the path length upto the latest
        // subdirectory at given depth
        unordered_map<int, int> pathLen;
        while (getline(ss, cur, '\n')) {
            auto depth = cur.find_last_of('\t');
            string name = (depth == string::npos) ? cur : cur.substr(depth + 1);
            if (cur.find(".") != string::npos) {
                // it is a file
                res = max(res, pathLen[depth - 1] + (int)name.length());
            } else {
                // it is a subdirectory
                // + 1 for '/' (after name)
                // pathLen[-1 (npos)] = name.length() + 1, eg "dir"
                // pathLen[0] = pathLen[-1] + name.length() + 1, eq "\tsubdir"
                pathLen[depth] = pathLen[depth - 1] + name.length() + 1;
            }
        }
        return res;
    }
};
/*
Main idea is to use hashmap to store the path length for each depth
(to be used by sub sub directories or files of current sub directory).

The depth is the number of '\t'. 

For each filename, calculate the path length by the current depth and
update the maximum path length.

Note: \t is a single character

E.g.
dir

\tsubdir1
\t\tfile1.ext
\t\tsubsubdir1

\tsubdir2
\t\tsubsubdir2
\t\t\tfile2.ext

We have two files:
"dir/subdir1/file1.ext" of length 21
"dir/subdir2/subsubdir2/file2.ext" of length 32
*/
