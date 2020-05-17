# Time:  O(min(n, h)), per operation
# Space: O(min(n, h))

class TrieNode:
    def __int__(self):
        self.isCompleteWord = False
        self.children = {}

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isCompleteWord = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.searchHelper(word, 0, self.root)

    def searchHelper(self, word, start, cur):
        if start == len(word):
            return cur.isCompleteWord
        if word[start] in cur.children:
            return self.searchHelper(word, start+1, cur.children[word[start]])
        elif word[start] == '.':
            for c in cur.children:
                if self.searchHelper(word, start+1, cur.children[c]):
                    return True

        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

# Notes: AttributeError: TrieNode object has no attribute children (Line 23)
