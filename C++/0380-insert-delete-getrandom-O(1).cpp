// Time:  O(1)
// Space: O(n)

class RandomizedSet {
private:
    vector<int> set;
    unordered_map<int, int> getindex;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (getindex.count(val))
            return false;
        set.push_back(val);
        // or .emplace_back
        getindex[val] = set.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!getindex.count(val))
            return false;
        getindex[set.back()] = getindex[val];
        swap(set[getindex[val]], set.back());
        getindex.erase(val);
        set.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return set[rand() % set.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Notes:
// Can't use hashmap/hashset as getrandom can't be implemented
// because map doesn't have indices
//
// Can't use array as it doesn't provide O(1) remove
