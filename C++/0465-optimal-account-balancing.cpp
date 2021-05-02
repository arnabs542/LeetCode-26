// Tags: Backtracking DP Google Premium
// Time: O(n!), where n = number of non-zero balances, since T(n) = n * T(n - 1)
// Space: O(n)
// Similar to 1723-find-minimum-time-to-finish-all-jobs
class Solution {
    vector<long> debt;
    // returns the minimum number of transactions to settle debts for debt[i:]
    int backtrack(int i) {
        // get next non-zero debt
        while (i < debt.size() && !debt[i])
            ++i;
        // or unordered_set<int> seen;
        int res = INT_MAX, prev = 0;
        for (int j = i + 1; j < debt.size(); ++j) {
            // skip already tried debted value and same sign debts (opt 1)
            // or !seen.count(debt[j]) && debt[j] * debt[i] < 0
            if ((prev != debt[j]) && debt[j] * debt[i] < 0) {
                // or seen.insert(debt[j]);
                debt[j] += debt[i]; // settle debt[i] with debt[j]
                res = min(res, 1 + backtrack(i + 1));
                prev = (debt[j] -= debt[i]); // backtrack and try another debt[j]
            }
        }
        return i == debt.size() ? 0 : res;
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> bal;
        for (auto t : transactions) {
            bal[t[0]] -= t[2];
            bal[t[1]] += t[2];
        }
        for (auto p : bal)
            if (p.second)
                debt.push_back(p.second);
        // no need to sort if using unordered_set
        sort(debt.begin(), debt.end()); // (opt 2)
        return backtrack(0);
    }
};
/*
Use an array debt[] to store all non-zero balances, where
    debt[i] > 0 means a person needs to pay $ debt[i] to other person(s).
    debt[i] < 0 means a person needs to collect $ debt[i] back from other person(s).

Starting from first debt debt[i], we look for all other debts debt[j] (j > i) which have
opposite sign to debt[i]. 

Then each such debt[j] can make one transaction debt[j] += debt[i] to clear the person with
debt debt[i]. 

From now on, the person with debt debt[i] is dropped out of the problem and we recursively
drop persons one by one until everyone's debt is cleared meanwhile updating the minimum number
of transactions during Dfs. (at last i becomes debt.size() which returns 0).
*/



// To do: Bitmask Dp solution
