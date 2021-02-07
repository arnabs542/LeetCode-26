// Tags: Amazon Design Hash-table Premium
// Time: O(1), except constructor
// Space: O(n)
class FirstUnique {
    list<int> unique;
    // value, list iterator
    unordered_map<int, list<int>::iterator> iter;
public:
    FirstUnique(vector<int>& nums) {
        for (auto &value: nums) {
            add(value);
        }
    }
    
    int showFirstUnique() {
        return unique.empty() ? -1 : unique.front();
    }
    
    void add(int value) {
        // or iter.find(value) == iter.end()
        if (!iter.count(value)) {
            // not in map (new value)
            // add to list
            unique.push_back(value);
            // add to map with iterator
            iter.insert({value, prev(unique.end())});
        } else if (iter[value] != unique.end()) {
            // present in map && iterator not invalid
            // (value is unique currently)
            // remove from list
            unique.erase(iter[value]);
            // invalidate iterator in map
            iter[value] = unique.end();
        }
    }
};

/*
Keep only unique numbers in the list (we use linked list as value can be
removed in O(1) time). Also first unique value will always be at head of linked
list (accessed in O(1) time).

If number is already in the map and it was unique before (i.e. had a valid
iterator) remove it from the list and mark it by making its iterator invalid (i.e
equal to list.end()).

Iterator states:
1. Iterator not present, if this value is never seen before
2. unique.end() (invalid), if this value is seen before
3. In range [unique.begin(), unique.end()), if the value is unique
*/
