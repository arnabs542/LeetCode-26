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


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> lookup(banned.cbegin(), banned.cend());
        unordered_map<string, int> counts;
        string word;
        for (const auto& c : paragraph) {
            if (isalpha(c)) {
                word.push_back(tolower(c));
            } else if (!word.empty()) {
                ++counts[word];
                word.clear();
            }
        }
        if (!word.empty()) {
            ++counts[word];
        }
        string result;
        for (const auto& kvp : counts) {
            if ((result.empty() || kvp.second > counts[result]) &&
                !lookup.count(kvp.first)) {
                result = kvp.first;
            }
        }
        return result;
    }
};
