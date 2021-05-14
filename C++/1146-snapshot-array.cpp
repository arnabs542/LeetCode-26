// Tags: Array Google
// Time: ctor: O(n), n = length
//       set: O(logs), s = max no. of times set() is called for same index
//       snap: O(1)
// Space: O(n + s), s = total no. of times set() is called
class SnapshotArray {
    vector<map<int, int>> snaps;
    int snap_id = 0;
public:
    SnapshotArray(int length) {
        // initially each element equal 0
        // (snap_id = 0)
        snaps.resize(length);
        for (int i = 0; i < length; ++i)
            snaps[i].insert({0, 0});
    }
    
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        // if we use lower_bound, there will be two cases:
        // 1: if key (snap_id) exists, we return its value
        // 2: if key doesn't exist, we return the value of the very previous key (snap_id) at
        // which the value of index was last changed
        auto it = snaps[index].upper_bound(snap_id);
        return (--it)->second;
    }
};
