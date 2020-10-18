// Tags: Amazon Heap Design
// Time:  O(logn) per addNum, O(1) per findMedian.
// Space: O(n), total space
// Two Heaps solution
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
        // or if (min_heap.empty() || num > min_heap.top())
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


// Time: O(logn + n) ~ O(n), per addNum
// Binary search takes logn, whereas insertion can take upto n as
// elements have to be shifted.
// Space: O(n)
// Insertion sort solution
class MedianFinder {
private:
    vector<int> data;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (data.empty())
            data.push_back(num);
        else
            data.insert(data.begin() + search(num)+1, num);
            // or data.insert(lower_bound(data.begin(), data.end(), num), num);
    }

    double findMedian() {
        int n = data.size();
        return n & 1 ? data[n/2] : ((double) data[n/2 - 1] + data[n/2])/2;

    }
    int search(int num) {
        int left = 0, right = data.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (data[mid] <= num) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
