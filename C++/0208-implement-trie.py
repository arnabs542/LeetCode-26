// Time: O(n), per operation
// Space: O(1)

class TrieNode {
public:
    TrieNode(): isCompleteWord(false) {
    }
    bool isCompleteWord;
    unordered_map<char, TrieNode*> children;
};


class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto *cur = root;

        for (const auto &c: word) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isCompleteWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto *node = childSearch(word);
        if (node) {
            return node->isCompleteWord;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }

    TrieNode *childSearch(string word) {
        auto *cur = root;
        for (const auto &c : word) {
            if (cur->children.count(c))
                cur = cur->children[c];
            else
                return nullptr;
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
