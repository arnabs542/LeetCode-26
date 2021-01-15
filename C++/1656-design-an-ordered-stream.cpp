// Tags: Array Design WC215
// Time: O(n)
// Space: O(n)
class OrderedStream {
    vector<string> s;
    int ptr = 1;
public:
    OrderedStream(int n): s(n + 1) {
        
    }
    
    vector<string> insert(int id, string value) {
        s[id] = value;
        vector<string> res;
        if (ptr != id)
            return res;
        for (int i = id; i < s.size() && !s[i].empty(); ++i) {
            res.push_back(s[i]);
            ptr++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
