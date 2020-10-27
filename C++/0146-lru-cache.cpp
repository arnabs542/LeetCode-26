// Tags: Amazon Design
// Time:  O(1), per operation.
// Space: O(k), k is the capacity of cache.
class LRUCache {
private:
    // pair<int, int> represents a node in linked list (key, value)
    list<pair<int, int>> list_;
    // key, list iterator ie reference to node
    unordered_map<int, list<pair<int, int>>::iterator> map_;
    int cap_;

    // if a node with this key exists, remove it
    // otherwise just add append a new node with this key and update the reference
    // in the map
    void update(int key, int value) {
        auto it = map_.find(key);
        // if key exists
        if (it != map_.end())
            list_.erase(it->second);
        list_.emplace_back(key, value);
        map_[key] = --list_.end();
    }
public:
    LRUCache(int capacity): cap_ {capacity} {

    }

    // if key exists, return its corresponding value and update the node
    int get(int key) {
        if (!map_.count(key))
            return -1;
        const auto value = map_[key]->second;
        update(key, value);
        return value;
    }

    void put(int key, int value) {
        if (!map_.count(key) && cap_ == list_.size()) {
            auto del_key = list_.front().first; list_.pop_front();
            map_.erase(del_key);
        }
        update(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
