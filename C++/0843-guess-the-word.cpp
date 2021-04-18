// Tags: Google Minimax
// Time: O(n), iterate all words atmost 10 times
// Space: O(n)
// Shuffle the wordlist
class Solution {
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i])
                ++matches;
        }
        return matches;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        random_shuffle(wordlist.begin(), wordlist.end());
        // or omit this operation
        // till x != 6 and i < 10
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            string guess = wordlist[0];
            // or string guess = wordlist[rand() % wordlist.size()];
            x = master.guess(guess);
            vector<string> tmp;
            // keep only those words in list for which number of matches with guess equals x
            for (string word: wordlist)
                if (match(guess, word) == x)
                    tmp.push_back(word);
            wordlist = tmp;
        }
    }
};
/*
Intuition:
Take a word from wordlist and guess it
Get the matches of this word
Update our wordlist keeping only the words having same number of matches to our guess

The key point is, which word should we guess from all of the wordlist?
*/



// Time: O(n)
// Space: O(n)
// Elimination histogram
class Solution {
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i])
                ++matches;
        }
        return matches;
    }
    string bestCandidate(list<string>& words, vector<vector<int>>& probs) {
        string best;
        int max_score = 0;
        for (auto w : words) {
            // score of current word =
            // product of prob of each char at its index i
            int score = 1;
            for (auto i = 0; i < 6; ++i)
                score *= probs[i][w[i] - 'a'];
            if (score > max_score) {
                max_score = score;
                best = w;
            }
        }
        return best;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<vector<int>> probs(6, vector<int>(26));
        list<string> rem_words;
        // initialize list and build histogram
        for (auto w : wordlist) {
            rem_words.push_back(w);
            for (auto i = 0; i < 6; ++i)
                probs[i][w[i] - 'a'] += 1;
        }
        int res = 0;
        while (res < 6) {
            string candidate = bestCandidate(rem_words, probs);
            res = master.guess(candidate);
            for (auto it = rem_words.begin(); it != rem_words.end();) {
                if (match(*it, candidate) != res) {
                    // erase it
                    // update histogram
                    for (auto i = 0; i < 6; ++i)
                        probs[i][(*it)[i] - 'a'] -= 1;
                    // iterator following the removed element is returned
                    it = rem_words.erase(it);
                } else {
                    // keep it
                    ++it;
                }
            }
        }
    }
};
/*
We can compute a position/character histogram for remaining words and use it to select
the next word to guess (O(n)). After each guess, we eliminate all words with different
similarity and update the histogram.

In order to reduce the number of guesses, the strategy is to pick such a word that would
maximize the amount of information (have high probability of matching with the secret word)
we can get per each guess.
*/



// To do: using minimax
