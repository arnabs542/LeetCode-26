// Tags: Stack Amazon
// Time: O(n)
// Space: O(n)
// Monotonic-stack solution
class StockSpanner {
    // we chose a pair in order to record results for previous answers
    // we can instead use a hash table as well to record those answers
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && price >= st.top().first) {
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
This is equivalent to finding first next largest element for current element.

So we need Decreasing Monotonic Stack and we iterate from Right to Left.
However instead of updating the result for popped elements, we update result
for the current element (which is being pushed onto the stack)
*/
