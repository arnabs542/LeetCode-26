// Tags: WC214 Greedy Sort Math Amazon
// Time: O(nlogn)
// Space: O(1)
// Greedy solution
class Solution {
public:
    int maxProfit(vector<int>& inv, int orders) {
        sort(inv.begin(), inv.end());
        long res = 0, colors = 1;
        for (size_t i = inv.size() - 1; i != -1; --i, ++colors) {
            long cur = inv[i], prev = i > 0 ? inv[i - 1] : 0;
            // we add 'colors' no of identical values [x x x....]  in one round
            // 'rounds' tells the no of such (complete) rounds we take
            // 'cur - prev' tells the no of such complete rounds possible before
            // cur becomes equal to prev and we have to move to next index
            long rounds = min(orders / colors, cur - prev);
            // update the number of orders left to be processed
            orders -= rounds * colors;
            // using formula for sum of natural no's n*(n + 1)/2 to get sum of no's b/w range (prev, cur]
            // * colors
            res = (res + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % 1000000007;
            if (cur - prev > rounds) {
                // (no of complete rounds possible are more than the no of complete rounds required)
                // take half round if orders != 0 and break
                res = (res + orders * (cur - rounds)) % 1000000007;
                break;
            }
        }
        return res;
    }
};

/*
colors = 1, [2 4 6 8 10], rounds = 2    =>  (10) + (9)
colors = 2, [2 4 6 8 8], rounds = 2     =>  (8 + 8) + (7 + 7)
colors = 3, [2 4 6 6 6], rounds = 2     =>  (6 + 6 + 6) + (5 + 5 + 5)
colors = 4, [2 4 4 4 4], rounds = 2     =>  (4 + 4 + 4 + 4) + (3 + 3 + 3 + 3)
colors = 5, [2 2 2 2 2], rounds = 2     =>  (2 + 2 + 2 + 2 + 2) + (1 + 1 + 1 + 1 + 1)

In the last iteration the numbers of orders left will fall short ie cur - prev > rounds
If the remaining number of orders are not exactly divisible by colors, we increment the
result by orders number of balls of value (cur - rounds) and break the loop. Otherwise,
if it is exactly divisible, we add 0 to res (since orders would be 0) and break the loop.
*/
