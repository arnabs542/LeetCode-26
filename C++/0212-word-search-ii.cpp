// Tags: Amazon Backtracking Trie
// TLE: Time limit exceeded (To check)
class TrieNode {
    public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord {false} {
        
    }
};

class Trie {
    public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto *cur = root;
        for (auto c: word) {
            if(!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> res;
        for (auto w: words)
            trie.insert(w);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, trie.root, i, j, "", res);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>> &board, TrieNode *cur, int i, int j, string sofar, vector<string> &res) {
        if (cur->isWord) {
            res.push_back(sofar);
            cur->isWord = false;
            //return;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        char c = board[i][j];
        if (!cur->children.count(c))
            return;
        
        board[i][j] = '#';
        
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto &d: directions) {
            int ni = i + d.first, nj = j + d.second;
            dfs(board, cur->children[c], ni, nj, sofar + c, res);
        }
        board[i][j] = c;
    }
};
