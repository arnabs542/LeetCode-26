// Tags: Amazon Hash-table String
// Time O(n*slogs + n*glogg), g is the max size of groups, s in max size of strings
// Space O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> groups;
        // key is a string whereas value is a vector of strings
        for (const auto &str : strs){
            string tmp {str};
            sort(tmp.begin(), tmp.end());
            groups[tmp].emplace_back(str);
            // emplace_back same a push_back as
            // for already constructed object
            // copy/move constructor will be called
        }

        vector<vector<string>> anagrams;
        
        for (const auto &group : groups){
            vector<string> instances {group.second};
            // sorting not necessary
            sort(instances.begin(),instances.end());
            anagrams.emplace_back(move(instances));
        }
        return anagrams;
    }
};
