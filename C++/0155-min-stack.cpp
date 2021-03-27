// Tags: Stack Design Amazon
// Time: O(1)
// Space: O(n)
// Value, min pair
class MinStack {
    // value, min seen so far (commulative min)
    stack<pair<int, int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        int cur_min = st.top().second;
        st.push({val, min(cur_min, val)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



// Time: O(1)
// Space: O(n)
// Basic calculator logic
class MinStack {
    stack<int> st;
    // current minimum
    int res = INT_MAX;
public:
    MinStack() {
        
    }
    void push(int val) {
        // only push the old minimum value when the current 
        // minimum value changes after pushing the new value x
        // or val == res
        if (val <= res) {
            // save old res
            st.push(res);
            // start new result
            res = val;
        }
        st.push(val);
    }
    
    void pop() {
        // if pop operation could result in the changing of the current minimum value, 
        // pop twice and change the current minimum value to the last minimum value.
        int val = st.top();
        st.pop();
        if (val == res) {
            res = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return res;
    }
};
