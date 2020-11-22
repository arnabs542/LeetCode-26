// Tags: WC216
// Failed attempt: time limit exceeded, input in order 1e5
class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> dict {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        string res;
        helper(n, k, dict, res, "");
        return res;
    }
    
    bool helper(int n, int k, vector<char> &dict, string &res, string prev) {
        if (k == 0) {
            res = prev;
            return true;
        }
        if (n == 0)
            return false;
        
        for (auto ch: dict) {
            if (helper(n - 1, k - (ch - 'a' + 1), dict, res, prev + ch))
                return true;
        }
        
        return false;
    }
};



// Time: O(n)
// Space: O(1)
// Greedy Solution (reverse fill)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        // n acts as index to res
        while (k > 0) {
            res[--n] += min(25, k);
            k -= min(25, k);
        }
        return res;
    }
};

/*
1. Build the string of length k, which consists of letter 'a'(lexicographically smallest string).
2. Increment string from right to left until it's value won't reach the target ('a' + 25 or 'a' + k)
*/
