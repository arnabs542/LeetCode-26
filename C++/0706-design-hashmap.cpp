// Tags: Amazon Hash-table Design
// Time: O(1) ~ O(100), in worst case atmost 100 operations (1000000/10000)
//       can end up at same bucket
// Space: O(10000 + 10000), 10000 buckets and 10000 operations (unique keys)
// Implementing Chaining (open hashing technique)
class MyHashMap {
    size_t numChains = 10000;
    vector<list<pair<int, int>>> data;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data.resize(numChains);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &chain = data[key % numChains];
        for (auto &p: chain) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &chain = data[key % numChains];
        auto it = find_if(chain.begin(), chain.end(), [&key](const auto &p) {
            return p.first == key;
        });
        return it == chain.end() ? -1 : it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &chain = data[key % numChains];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }
};

/*
A prime number like 997 in hash function reduce number of collisions by neutralizing the effect
of patterns in the keys by distribution of collisions (two different keys mapped 
to the same address) of a hash function.
*/
