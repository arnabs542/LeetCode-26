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
        // if key exists, remove from list
        if (it != map_.end())
            list_.erase(it->second);
        list_.emplace_back(key, value);
        map_[key] = --list_.end();
        // or prev(end(list_))
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
            // definitely adding this node will increase size
            auto del_key = list_.front().first; list_.pop_front();
            // this is the reason we store key in list as well
            map_.erase(del_key);
        }
        update(key, value);
    }
};
/* keep most recently used at tail and least recently used at head */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



// Using class object instead of pair<int, int>
class Node {
public:
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key {k}, val {v}, prev {nullptr}, next {nullptr} {

    }
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> dict;
    Node *head, *tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // boundary dummy nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node *node) {  
        node->prev->next = node->next;
        node->next->prev = node->prev;
        //delete node;
    }
    
    void add(Node *node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    
    int get(int key) {
        if (dict.count(key)) {
            Node *node = dict[key];
            remove(node);
            add(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            remove(dict[key]);
            delete dict[key];
        }
        Node *node = new Node(key, value);
        add(node);
        dict[key] = node;
        if (dict.size() > capacity) {
            Node *p = head->next;
            remove(head->next);
            dict.erase(p->key);
            delete p;
        }
        }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 