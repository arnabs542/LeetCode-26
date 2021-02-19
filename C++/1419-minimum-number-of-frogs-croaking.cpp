// Tags: String C3.ai
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {}, frogs = 0, max_frogs = 0;
        for (char ch : croakOfFrogs) {
            auto i = string("croak").find(ch);
            ++cnt[i];
            if (i == 0) {
                // like bracket matching c -> ( and k -> )
                // for each c (opening bracket) seen before k, we increase the count
                max_frogs = max(max_frogs, ++frogs);
            } else if (--cnt[i - 1] < 0) {
                // previous letter not seen
                return - 1;
            } else if (i == 4) {
                // we decrease count when k (closing bracket) is seen
                --frogs;
            }
        }
        // frogs > 0 meaning k not seen for all frogs
        // frogs < 0 meaning k is present more times than other letters
        return frogs == 0 ? max_frogs : -1;
    }
};
/*
Consider frog yelling letters as a wave.
As a frog yells "croak", the wave travels along the string
increasing count of current letter and decreasing count of previous letter.
At any point, if a frog yelled a letter but didn't yell the previous letter,
we return -1.
If we see 'c', we increase the frog count and if we see 'k', we decrease the
frog count.
max_cnt records the maximum frog count achieved.
*/
