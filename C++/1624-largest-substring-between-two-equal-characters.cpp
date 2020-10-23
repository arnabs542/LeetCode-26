// Tags: WC211
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        vector<int> left(26, INT_MAX);
        for (auto i = 0; i < s.length(); ++i) {
            if (left[s[i] - 'a'] == INT_MAX)
                left[s[i] - 'a'] = i;
            result = max(result, i - left[s[i] - 'a'] - 1);
        }
        return result;
    }
};


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        int left[26] {};
        for (auto i = 0; i < s.length(); ++i) {
            if (left[s[i] - 'a'] == 0)
                left[s[i] - 'a'] = i + 1;
            result = max(result, i - left[s[i] - 'a']);
        }
        return result;
    }
};
