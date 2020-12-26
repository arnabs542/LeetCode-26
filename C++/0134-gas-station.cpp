// Tags: Greedy
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Property 1: compare total cost and total gas
       if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
           return -1;
        int i = 0, remainGas = 0;
        
        // Property 3: no loop around, j < gas.size()
        for (int j = 0; j < gas.size(); ++j) {
            remainGas += gas[j] - cost[j];
            if (remainGas < 0) {
                // Property 2: set the starting point to j + 1
                i = j + 1;
                remainGas = 0;
            }
        }
        return i;
    }
};
