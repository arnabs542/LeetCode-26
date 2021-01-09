// Tags: Amazon Design
// Time: O(1), except constructor
// Space: O(n)
class FirstUnique {
    list<int> unique;
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
        if (!iter.count(value)) {
            unique.push_back(value);
            iter.insert({value, prev(unique.end())});
        } else if (iter[value] != unique.end()) {
            unique.erase(iter[value]);
            iter[value] = unique.end();
        }
    }
};

/*
Keep only unique numbers in the list.

If number is already in the map and it was unique before (i.e. had a valid
iterator) remove it from the list and mark it by making its iterator invalid (i.e
equal to list.end()).
*/

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
