# Time:  O(m * n * l), l is height of Trie
# Space: O(l)

from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        cur = self.root
        for c in word:
            cur = cur.children[c]
        cur.isWord = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res, trie = [], Trie()

        node = trie.root

        for w in words:
            trie.insert(w)

        for i, row in enumerate(board):
            for j, col in enumerate(board[0]):
                self.dfs(board, node, i, j, "", res)
        return res

    def dfs(self, board, node, i, j, path, res):
        if node.isWord:
            res.append(path)
            # don't want to add this word multiple times
            node.isWord = False

        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return

        c = board[i][j]
        if c not in node.children:
            return

        board[i][j] = '#'

        for ni, nj in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
            self.dfs(board, node.children[c], ni, nj, path + c, res)

        board[i][j] = c


# Notes: In dfs the 'node' and 'path' is from previous step
# We put the cell value temporarily as # so that it won't be
# included again in the same word. Once we return we put back the value

# in most cases in dfs, cur actually refers to prev
