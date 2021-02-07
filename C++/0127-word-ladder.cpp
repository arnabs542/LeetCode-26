// Tags: Amazon BFS
// Time: O(list_length * word_length * lookup_time), there can only be list_length
//       number of elements in the queue., lookup_time = O(1) here
// Space: O(list_length * word_length)
// Time limit exceeded
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder = 0;
        while (!q.empty()) {
            int n = q.size();
            // complete whole level before incrementing
            // ladder count
            while (n > 0) {
                string cur = q.front(); q.pop();
                if (cur == endWord)
                    return ladder + 1;
                // don't go back to visited strings
                dict.erase(cur);
                // replace char at every index
                for (int i = 0; i < cur.length(); ++i) {
                    char c = cur[i];
                    // try replacing each char with all 26 chars possible
                    for (int k = 0; k < 26; ++k) {
                        cur[i] = 'a' + k;
                        if (dict.find(cur) != dict.end())
                            q.push(cur);
                    }
                    cur[i] = c;
                }
                --n;
            }
            ++ladder;
        }
        return 0;
    }
};



// Time: O(list_length * word_length * lookup_time), each word in wordList
//       can either be in head set or tail set, as we keep removing them from dict
//       hence list_length. (same complexity but search time reduces to half),
//       lookup_time = O(1) here. 
// Space: O(list_length * word_length)
// Two-end BFS search method
// (Bidirectional Bfs)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set is used for head and tail so that we can search if word is in ptail set
        // in O(1) time
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end())
            return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head; // phead is the forward set
                ptail = &tail; // ptail provides the target node for phead to search
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> nextlev;
            for (auto it = phead->begin(); it != phead->end(); ++it) {
                string word = *it;
                // change char at each index
                // (reference to c as we are editting original
                // word)
                for (auto &c: word) {
                    char ch = c;
                    // try all 26 chars
                    for (int k = 0; k < 26; ++k) {
                        c = 'a' + k;
                        // when ptail points to the very next level to phead
                        // lookup return true
                        // (equivalent to if(word == endWord) in previous sol)
                        if (ptail->find(word) != ptail->end())
                            return ladder;
                        
                        if (dict.find(word) != dict.end()) {
                            nextlev.insert(word);
                            dict.erase(word);
                        }
                    }
                    c = ch;
                }
            }
            ++ladder;
            *phead = nextlev; // or phead->swap(nextlev);
        }
        return 0;
    }
};
/*
Each BFS uses two sets (nextlev, phead) instead of a queue
Here, we alternatively travel from startWord and endWord.
(It is faster as we are pruning Bfs tree by avoiding choices that absolute has no
chance of leading to the final result)

Why Bidirectional Breadth First Search?
The search space considered by breadth first search algorithm depends upon the
branching factor of the nodes at each level. If branching factor remains same for
all nodes (atmost 26*word_length choices), search space increases exponentially
along with the no. of levels.
We can considerably cut down search space of the standard breadth first search
algorithm if we launch two simulatenous BFS. One from beginWord and one from
endWord. We progress one node at a time from both sides and at any point in time
if we find a common node in both the searches, we stop the search.

So bidirectional Bfs considerably cuts down the search space and
hence reduces time and space complexity.
*/
