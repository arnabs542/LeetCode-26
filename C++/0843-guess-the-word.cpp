/*
Intuition:
Take a word from wordlist and guess it
Get the matches of this word
Update our wordlist keeping only the words having same number of matches to our guess

The key point is, which word should we guess from all of the wordlist?
*/


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
