// Tags: Array Amazon Premium
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int findCelebrity(int n) {
        // first pass: finding candidate
        // assume 0 is celebrity
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            // if candidate knows i, it is not a celebrity
            if (knows(candidate, i)){
                // so i could be celebrity
                candidate = i;
            }
        }
        // second pass: verifying if candidate found is actually
        // a celebrity
        for (int i = 0; i < n; ++i) {
            // if candidate knows someone (out of indices before candidate) or someone (out of all) 
            // doesn't know candidate he is not a celebrity
            if (i != candidate && (knows(candidate, i) || !knows(i, candidate)))
                return -1;
        }
        return candidate;
    }
};

/*
if candidate is celebrity, 
    !knows(candidate, 0 to n - 1), he knows no one
    and knows(0 to n - 1, candidates), everyone knows him
*/
