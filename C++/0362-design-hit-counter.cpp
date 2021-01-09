// Tags: Amazon Design Premium
// Time: O(1)
// Space: O(300) ~ O(1)
class HitCounter {
    // timestamp, count;
    queue<pair<int, int>> q;
    int hits;
public:
    /** Initialize your data structure here. */
    HitCounter(): hits(0) {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while (!q.empty() && timestamp - q.front().first >= 300) {
            hits -= q.front().second; q.pop();
        }
        if (!q.empty() && q.back().first == timestamp)
            ++q.back().second;
        else
            q.push({timestamp, 1});
        ++hits;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front().first >= 300) {
                hits -= q.front().second; q.pop();
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

/*
We use a queue to keep track of the hits, and each element in the queue
is a pair of timestamp $t and the cnt of the hits at time $t. And we use
a counter to keep track of the number of hits within 300s.

When a hit comes, we need to maintain the queue and pop the
(timestamp, hit_cnt) pair iff it is not in last 300 second.

Since it take O(1) to push/pop each element in queue and each element
only goes into the queue once, the time complexity of all operations
is O(1) in an aggregated sense.

Follow up:
Q: What if the number of hits per second could be very large? 
   Does your design scale?
A: Yes, as in that case we only increase the count of the pair which
   is already present in the queue.
*/
