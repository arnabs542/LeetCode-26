// Tags: Amazon Design Premium
// Time:  ls: O(l + klogk), l is the path length, k is the number of entries in the last level directory
//        mkdir: O(l)
//        addContentToFile: O(l + c), c is the content size
//        readContentFromFile: O(l + c)
// Space: O(n + s), n is the number of dir/file nodes, s is the total content size.
class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode*> children;
        TrieNode(): isFile(false) {
            
        }
    };
    TrieNode* root;

    // convert path into a list of strings dereferenced by /
    vector<string> getStrs(string path) {
        // paths always begin with '/'
        int i = 1, j = 1;
        vector<string> res;
        // same as what getline does
        while (j <= path.length()) {
            if (i != j && (j == path.length() || path[j] == '/')) {
                res.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        return res;
        // or
        // vector<string> ans;
        // stringstream ss(s);
        // string t;
        // while (!ss.eof()) {
        //     getline(ss, t, '/');
        //     ans.push_back(t);
        // }
        // return ans;
    }
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getStrs(path);
        TrieNode* cur = root;
        for (string &str: strs) {
            cur = cur->children[str];
        }
        if (cur->isFile)
            return {strs.back()};
        vector<string> res;
        for (auto &kvp: cur->children) {
            res.push_back(kvp.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path) {
        vector<string> strs = getStrs(path);
        TrieNode* cur = root;
        for (string &str: strs) {
            if (!cur->children.count(str))
                cur->children[str] = new TrieNode();
            cur = cur->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getStrs(filePath);
        TrieNode* cur = root;
        for (string &str: strs) {
            // creates a node for the file ie strs.back()
            if (!cur->children.count(str))
                cur->children[str] = new TrieNode();
            cur = cur->children[str];
        }
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getStrs(filePath);
        TrieNode* cur = root;
        for (string &str: strs)
            cur = cur->children[str];
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
