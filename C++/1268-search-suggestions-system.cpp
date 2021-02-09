// Tags: Amazon Trie String
// Time: O(NlogN) for sorting, O(logN) for each prefix query
// => O(l*logN), not sure
// Space: O(l), l is length of each query
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        string cur; // prefix
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            auto it = lower_bound(products.begin(), products.end(), cur);
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string s = *(it + i);
                // if s doesn't start with cur, neither will the following strings
                if (s.find(cur) == string::npos)
                    break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
/*
In a sorted list of words, for any word A[i], all its sugested words
(if present) must following this word in the list.

With this observation, we can binary search the position of each prefix
in the sorted list, and check if the next 3 words are valid suggestions
*/



// Time: build tree -> O(n * l), n = number of products
//       l = average length of product names
//       suggest -> O(l^2) // or O(l), not sure
// Space: O(t), t = number of nodes in trie
struct TrieNode {
    // stores smallest 3 strings that are present in the
    // prefix tree rooted at this node (with current prefix)
    priority_queue<string> max_heap;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (string p: products)
            buildTree(root, p);
        // even if no children of current node present, we mush have
        // an empty vector
        vector<vector<string>> res(searchWord.length());
        auto cur = root;
        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            // if current node doesn't have a child mapped to char c
            // we break and return empty vectors for every char past
            // this point
            if (!cur->children.count(c))
                break;
            vector<string> tmp;
            cur = cur->children[c];
            priority_queue<string> maxHeapCopy = cur->max_heap;
            while (!maxHeapCopy.empty()) {
                tmp.push_back(maxHeapCopy.top()); maxHeapCopy.pop(); // O(3log3)
            }
            reverse(tmp.begin(), tmp.end()); // O(3)
            res[i] = tmp;
        }
        return res;
    }
    
    void buildTree(TrieNode* root, string word) {
        auto cur = root;
        for (char c : word) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->max_heap.push(word);
            if (cur->max_heap.size() > 3)
                cur->max_heap.pop();
        }
    }
};



// First attempt (very inefficient), time limit exceeded
struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord {false} {
        
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
       root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    void dfs(TrieNode* root, string cur, vector<string> &res) {
        if (root->isWord) {
            res.push_back(cur);
        }
        for (auto &kvp : root->children) {
            dfs(kvp.second, cur + kvp.first, res);
        }
    }
    vector<string> startsWith(string prefix) {
        TrieNode* cur = root;
        vector<string> res;
        for (char c: prefix)
            if (cur->children.find(c) != cur->children.end())
                cur = cur->children[c];
            else
                return res;
        dfs(cur, prefix, res);
        sort(res.begin(), res.end());
        if (res.size() > 3)
            res = vector<string>(res.begin(), res.begin() + 3);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (string p: products)
            trie.insert(p);
        string cur;
        vector<vector<string>> res;
        for (char c: searchWord) {
            cur += c;
            res.push_back(trie.startsWith(cur));
        }
        return res;
    }
};
