// Tags: Design Amazon Premium
// Time: O(1)
// Space: O(k)
// Fifo like design (tail replaces wp & head replaces rp)
class MyCircularQueue {
private:
    // head : next position to be read
    // tail : next position to be written
    // (values between 0 to k - 1)
    int head, tail;
    vector<int> data;
    bool empty;
    // empty is the mark when the queue is empty
    // to differentiate from queue is full
    // because in both conditions (tail == head) stands
public:
    MyCircularQueue(int k) : head(0), tail(0), empty(true) {
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        // update the empty value when first enqueue happens
        // (all empty before) 
        if (head == tail && empty)
            empty = false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % data.size();
        // update the empty value when last dequeue happens
        // (all empty after)
        if (head == tail && !empty)
            empty = true;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return data[(tail - 1 + data.size()) % data.size()];
        // or
        // if (tail == 0)
        //   return data[data.size() - 1];
        // else
        //   return data[tail - 1];
        // so we add data.size() for case a when tail == 0;
    }
    
    bool isEmpty() {
        return head == tail && empty;
    }
    
    bool isFull() {
        return head == tail && !empty;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
