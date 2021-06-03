// Tags: Hash-table Google
// Time: O(n)
// Space: O(1), hashmap as atmost 10 elements (0 - 9)
// Two pass solution
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cnt;
        for (char c : secret)
            ++cnt[c];
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.length(); ++i) {
            char c= guess[i];
            if (cnt.count(c)) {
                if (secret[i] == c) {
                    ++bulls;
                    // if cnt[c] <= 0, it means this char was seen before and counted in the
                    // cows (as long as cnt[c] was > 0) and thus we have to UNDO the cows
                    // count by 1 (move it from cows groups to bulls group)
                    cows -= (cnt[c] <= 0);
                } else {
                    // only increment cows as long as cnt[c] > 0 (example 1)
                    cows += (cnt[c] > 0);
                }
                --cnt[c];
            }
        }
        return to_string(bulls).append("A").append(to_string(cows)).append("B");
    }
};
/*
Edge cases:

1.: 4 should be counted as cow only once
secret = 1 9 4 9
guess  = 4 4 2 2

2.: 4 shouldn't be counted as cow
secret = 1 9 4 9
guess  = 4 3 2 2
*/



// Time: O(n)
// Space: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cnt;
        int bulls = 0, cows = 0;
        for (int i = 0; i < guess.length(); ++i) {
            char g = guess[i], s = secret[i];
            if (s == g) {
                ++bulls;
            } else {
                cows += (cnt[g] > 0) + (cnt[s] < 0);
                // secret string gives a positive contribution, and
                // guess - negative contribution
                ++cnt[s];
                --cnt[g];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
/*
Extra edge cases for one pass solution
1.
secret = 1 2 3 4
guess =  4 2 1 9
             ^ *

2.
secret = 1 8 0 7
guess  = 7 8 1 0
               ^*
At ^, cnt[g] > 0 means char g was seen in secret earlier.
At *, cnt[s] < 0 means char s was seen in guess earlier.
*/
