// Tags: Queue Google Premium
// Time: O(1)
// Space: O(size)
class MovingAverage {
    int size, sum;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size), sum(0) {
        
    }
    
    double next(int val) {
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return 1.0 * sum / q.size();
    }
};
