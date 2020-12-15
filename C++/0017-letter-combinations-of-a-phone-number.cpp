// Time:  O(4^n)
// Space: O(4^n)
// BFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        unordered_map<char, string> mp {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},{'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        // queue<string> q;
        // q.push("");
        // for (size_t i = 0; i < digits.length(); ++i) {
        //     while (q.front().length() == i) {
        //         string path = q.front(); q.pop();
        //         for (char c: mp[digits[i]]) {
        //             q.push(path + c);
        //         }
        //     }
        // }
        vector<string> cur {""}, next;
        for (size_t i = 0; i < digits.length(); ++i) {
            for (auto x: cur)
                for (char c: mp[digits[i]])
                    next.push_back(x + c);
            cur = next;
            next.clear();
        
        }
        return cur;
    }
};
