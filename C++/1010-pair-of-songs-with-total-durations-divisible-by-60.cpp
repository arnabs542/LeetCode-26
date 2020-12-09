// Time:  O(n)
// Space: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        unordered_map<int, int> count;
        for (const auto &t: time) {
            result += count[(60 - t % 60) % 60];
            ++count[t % 60];
        }
        return result;
    }
};

/*
t % 60 gets the remainder from 0 to 59.
We count the occurrence of each remainders in a array/hashmap count.

We want to know that, for each t,
how many x satisfy (t + x) % 60 = 0.

The straight forward idea is to take x % 60 = 60 - t % 60,
which is valid for the most cases.

But if t % 60 = 0, x % 60 = 0 instead of 60.
Therefore we use x % 60 = (60 - t % 60) % 60.
*/
