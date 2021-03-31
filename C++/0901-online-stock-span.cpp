// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
// Monotonic-stack solution
class StockSpanner {
    // we chose a pair in order to record results for previous answers
    // we can instead use a hash table as well to record those answers
    // price, no of smaller consecutive prices(no of prices it caused to be popped)
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && price >= st.top().first) {
            // no of consecutive prices smaller than current price =
            // sum of (no of smaller consecutive prices) for the prices current price
            // caused to be popped.
            res  += st.top().second; st.pop();
        }
        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
We want to find previous leftmost smaller element for current element.
This is equivalent to finding (first) next larger element for that leftmost element.

So we need Decreasing Monotonic Stack and we iterate from Left to Right.
However instead of updating the result for popped elements, we update result
for the current element (which is being pushed onto the stack)
*/
