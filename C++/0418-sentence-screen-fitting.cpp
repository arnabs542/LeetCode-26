// Tags: Google DP Premium
// Time: O(rows)
// Space: O(1)
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto word: sentence)
            s += word + " ";
        int l = s.length(), start = 0;
        for (int i = 0; i < rows; ++i) {
            // possible start of next row
            start += cols;
            // adjust start
            if (s[start % l] == ' ') {
                // if start points to a space, remove it by incrementing once
                ++start;
            } else {
                // if start points to any word, add spaces by keep decrementing
                // until start - 1 points to a space
                while (start > 0 && s[(start - 1) % l] != ' ')
                    --start;
            }
        }
        // taking floor value
        return start / l;
    }
};
/*
Consider multiple non-repeating sentence strings s i.e "abc de f " arranged in a row.

"abc de f abc de f abc de f ..."
 ^      ^     ^    ^      ^
 0      7     13   18     25

Our goal is to find the start position of the row next to the last row on the screen,
which is 25 here. Since actually it's the length of everything earlier, we can get the answer
by dividing this number by the length of (non-repeated) sentence string. 25 / 6 = 4


Here is how we find that position. In each iteration, we need to adjust start based on spaces
either added or removed.

 0   4  7 9  13 16 18  22 25
"abc de f abc de f abc de f ..." -> start=0
 012345                          -> start=start+cols+adjustment=0+6+1=7 (1 space removed)
        012345                   -> start=7+6+0=13 (no adjustment required)
              012345             -> start=13+6-1=18 (1 space added)
                   012345        -> start=18+6+1=25 (1 space removed)
                          012345
*/



// Time: O(rows * (cols / w)), w = average word length
// Time limit exceeded
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int k = 0, cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols;) {
                if (j + sentence[k].size() - 1 < cols) {
                    j = j + sentence[k].size() + 1;
                    if (++k == sentence.size()) {
                        ++cnt;
                        k = 0;
                    }
                } else {
                    break;
                }
            }
        }
        return cnt;
    }
};



// To do: Dp solution
