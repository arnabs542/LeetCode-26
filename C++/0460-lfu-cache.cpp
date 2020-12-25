// Tags: Amazon Design
// Time:  O(1), per operation
// Space: O(k), k is the capacity of cache
class LFUCache {
    int capacity, size, minfreq  = 0;
    unordered_map<int, list<int>> fkeys;

    unordered_map<int, pair<int, int>> values;
    unordered_map<int, list<int>::iterator> iters;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        // current size
        size = 0;
    }

    void update(int key) {
        int oldfreq = values[key].second;
        auto it = iters[key];
        // increment freq
        ++values[key].second;
        // remove from old list
        fkeys[oldfreq].erase(it);
        // add to new list
        fkeys[oldfreq + 1].push_back(key);
        // update iterator
        iters[key] = prev(fkeys[oldfreq + 1].end());
        // update minfreq if necessary
        if (fkeys[minfreq].empty())
            ++minfreq;
    }

    int get(int key) {
        if (values.find(key) == values.end())
            return -1;
        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if (!capacity)
            return;

        if (values.find(key) != values.end()) {
            values[key].first = value;
            update(key);
        } else {
            // not already present
            if (size == capacity) {
                int evictkey = fkeys[minfreq].front();
                fkeys[minfreq].pop_front();
                values.erase(evictkey);
                iters.erase(evictkey);
            } else {
                ++size;
            }
            minfreq = 1;
            fkeys[1].push_back(key);
            values[key] = {value, 1};
            iters[key] = prev(fkeys[1].end());
        }
    }
};

/*
The main idea is to put all keys with the same frequency to a linked list
so the most recent one (at the tail) can be evicted.

minfreq is the smallest freqency so far
iters stores key's position in the linked list, key to list iterator
values stores key's value and freq, key to {value,freq}
keys stores key list for each freq, freq to key list
*/
