// Time: O(min(n, h)) for search() if no '.' else O(26^n), O(n) for addWord()
// Space: O(min(n, h)) for search(), O(1) for addWord()

struct TrieNode {
        bool isCompleteWord = false;
        unordered_map<char, TrieNode *> children;
};

class WordDictionary {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        root->isCompleteWord = true;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto *cur = root;
        for (const auto &c: word) {
            // no match
            if (cur->children.find(c) == cur->children.cend())
                cur->children[c] = new TrieNode;
            cur = cur->children[c];
        }
        cur->isCompleteWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
    dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int start, TrieNode *cur) {
        if (start == word.length())
            return cur->isCompleteWord;

        if (cur->children.find(word[start]) != cur->children.end()) {
            return searchHelper(word, start + 1, cur->children[word[start]]);
        } else if (word[start] == '.') {
            for (const auto &i: cur->children) {
                if (searchHelper(word, start + 1, i.second))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 /* Notes: Space required for search() is O(min(n, h)) because if n (string len)
 is less than h then our stack only goes upto height n */
