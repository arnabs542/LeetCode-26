class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // only check num > top if max_heap is not empty
        if (max_heap.empty() || num > max_heap.top()) {
            min_heap.emplace(num);
            if (min_heap.size() > max_heap.size() + 1) {
                max_heap.emplace(min_heap.top());
                min_heap.pop();
            }
        } else {
            max_heap.emplace(num);
            if (max_heap.size() > min_heap.size()) {
                min_heap.emplace(max_heap.top());
                max_heap.pop();
            }
        }
    }

    double findMedian() {
        return min_heap.size() == max_heap.size() ?
            (max_heap.top() + min_heap.top()) / 2.0 : min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// Notes:
// max_heap covers first half and min_heap covers the second half.
// Our balancing strategy is to keep min_heap with size either equal
// or 1 greater than max_heap size.
