// Tags: Trie Amazon Premium
// Time:  O(p^2), p is the length of the prefix
// Space: O(p * t + s), t is the number of nodes of trie
//                    , s is the size of the sentences
// Similar to 1268-search-suggestions-system
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    // count of sentences that have string upto current
    // node as their prefix
    unordered_map<string, int> counts;
};
class AutocompleteSystem {
    TrieNode* root;
    string prefix;
    void add(string sentence, int times) {
        TrieNode* cur = root;
        for (char c : sentence) {
            if (!cur->children.count(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
            cur->counts[sentence] += times;
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (auto i = 0; i < sentences.size(); ++i)
            add(sentences[i], times[i]);
    }
    vector<string> input(char c) {
        if (c == '#') {
            // since sentence is complete, add this to the tree
            add(prefix, 1);
            // reset prefix
            prefix.clear();
            return {};
        }
        // reach the final node (if available)
        prefix += c;
        TrieNode* cur = root;
        for (char ch : prefix) {
            if (!cur->children.count(ch))
                return {};
            cur = cur->children[ch];
        }
        // put all string in a priority queue
        // (think of comparison in terms of b instead of a (as we usually do))
        auto cmp = [](const auto& a, const auto &b) {
            return a.first == b.first ? a.second > b.second : b.first > a.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto& kvp : cur->counts) {
            pq.push({kvp.second, kvp.first});
        }
        vector<string> res;
        // remove the top 3
        for (int i = 0; i < 3 && !pq.empty(); ++i)
            res.push_back(pq.top().second), pq.pop();
        return res;
    }
};

/* Binary search approach might also work as in 
   1268-search-suggestions-system */
