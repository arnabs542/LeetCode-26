// Tags: BFS Amazon
// Time:  O(b^(d/2)), b is the branch factor of bfs, d is the result depth
// Space: O(w * l), w is the number of words, l is the max length of words
// Bidirectional BFS + Backtracking
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return {};
        unordered_map<string, unordered_set<string>> tree;
        unordered_set<string> head {beginWord}, tail {endWord};
        bool isFound = false, isReversed = false;
        while (!head.empty()) {
            // we remove all word in the list
            // at the start, necessary (different from word-ladder)
            for (const auto& word : head)
                dict.erase(word);
            unordered_set<string> new_head;
            for (const auto& word: head) {
                string new_word = word;
                for (int i = 0; i < new_word.length(); ++i) {
                    char c = new_word[i];
                    for (int k = 0; k < 26; ++k) {
                        new_word[i] = 'a' + k;
                        // not a valid word
                        if (!dict.count(new_word))
                            continue;
                        if (tail.count(new_word)) {
                            isFound = true; // endWord found
                            // don't break right away
                            // update tree and also continue visiting rest of the nodes
                            // in the current level as they might also find endWord
                        } else
                            new_head.insert(new_word);
                        
                        // build parent tree
                        if (!isReversed) {
                            // word is parent of new_word
                            tree[new_word].emplace(word);
                        } else {
                            // new_word is parent of word
                            tree[word].emplace(new_word);
                        }
                        
                    }
                    new_word[i] = c;
                }
            }
            if (isFound)
                break;
            head = move(new_head);
            if (head.size() > tail.size()) {
                // or swap(head, tail)
                head.swap(tail);
                isReversed = !isReversed;
            }
        }
        return backtracking(tree, beginWord, endWord);
    }
private:
    // although we have a backward tree (child to parent), we are
    // interating from top to bottom only (parent to child), as we
    // are performing postorder traversal
    // similar to sentences() of 0126-word-break-ii
    vector<vector<string>> backtracking(const unordered_map<string, 
            unordered_set<string>> &tree, const string &beginWord, 
            const string &word) {
        // current res (just like current root in postorder)
        vector<vector<string>> res;
        if (word == beginWord) {
            res.push_back({beginWord});
            return res;
        }
        
        if (tree.count(word)) {
            for (const auto &new_word : tree.at(word)) {
                auto paths = backtracking(tree, beginWord, new_word);
                // append (current) word to all the vectors of paths
                for (auto &path : paths) {
                    path.emplace_back(word);
                    res.push_back(move(path));
                }
            }
        }
        return res;
    }
};

// To do : Using BFS of paths
// ref: https://leetcode.com/problems/word-ladder-ii/discuss/40434/C%2B%2B-solution-using-standard-BFS-method-no-DFS-or-backtracking
