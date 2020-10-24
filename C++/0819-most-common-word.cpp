// Tags: Amazon String
// Time:  O(m + n), m is the size of banned, n is the size of paragraph
// Space: O(m + n)
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban {banned.begin(), banned.end()};
        // or ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto &c: paragraph)
            c = isalpha(c) ? tolower(c) : ' ';

        istringstream iss {paragraph};
        string word;
        pair<string, int> result {"", 0};
        while (iss >> word) {
            if (ban.find(word) == ban.end() && ++count[word] > result.second)
                result = {word, count[word]};
                // or make_pair(word, count[word]);
            }
        return result.first;
        }
};
