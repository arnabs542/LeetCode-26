// Tags: Array Google
// Time: O(s.len +  (sigma over i) words[i].len), we go through every word only once
// Space: O(words.size), at each point, only words.size() no. of pairs exists in waiting
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // array of buckets (indexed by char 'c') where each bucket stores pair {i, j}
        // telling ith word is waiting for char c (present at its jth index)
        // 0th bucket holds indices of all words that aren't waiting for anymore characters
        vector<pair<int, int>> waiting[123];
        // or unordered_map<char, vector<pair<int, int>>> waiting;
        for (int i = 0; i < words.size(); ++i)
            waiting[words[i][0]].push_back({i, 0});
        for (char c : s) {
            vector<pair<int, int>> advance = move(waiting[c]);
            // we clear at the start as a word may come again in the same bucket waiting
            // for the same character
            waiting[c].clear();
            // or waiting.erase(c);
            for (const auto& [i, j] : advance) {
                char nc = j + 1 == words[i].length() ? 0 : words[i][j + 1];
                waiting[nc].push_back({i, j + 1});
            }
        }
        return waiting[0].size();
    }
};
/*
I go through S once, and while I'm doing that, I move through all words accordingly.
That is, I keep track of how much of each word I've already seen, and
with each letter of S, I advance the words waiting for that letter. 

To quickly find the words waiting for a certain letter, I store each word (and its progress)
in a list of words waiting for that letter. Then for each of the lucky words whose current
letter just occurred in S, I update their progress and store them in the list for their next
letter.
*/
