// Tags: Design Hash-table Amazon Premium
// Time:  create: O(m), m = length of path string
//        get:    O(1)
// Space: O(k), k = no of unique paths we add
// (Here, it is not required to create Trie as we do in 0588-design-in-memory-file-system)
class FileSystem {
    unordered_map<string, int> files;
public:
    // root parent is present
    FileSystem(): files({{"", -1}}) {
        
    }
    
    bool createPath(string path, int value) {
        // O(m) searching for last '/' and
        // another O(m) for getting parent string
        string parent = path.substr(0, path.find_last_of('/'));
        if (!files.count(parent) || files.count(path))
            return false;
        files[path] = value;
        return true;
    }
    
    int get(string path) {
        if (!files.count(path))
            return -1;
        return files[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
