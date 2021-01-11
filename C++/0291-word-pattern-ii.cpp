// Tags: Backtracking Amazon Premium
// Time: C(len(pattern), len(str)), essentially we just 
//       want to partition str into len(pattern) groups.
// Space: O(len(pattern) + len(str))
// Similar to 0010-regular-expression-matching
// & 0044-wildcard-matching
class Solution {
    unordered_map<char, string> pat2str;
    unordered_set<string> strSet;
public:
    bool wordPatternMatch(string pattern, string s) {
        return isMatch(s, pattern, 0, 0);
    }
    bool isMatch(string s, string pattern, int i, int j) {
        // base case
        if (i == s.length() && j == pattern.length())
            return true;
        if (i == s.length() || j == pattern.length())
            return false;
        
        // get current pattern character
        char c = pattern[j];
        
        // if pattern character exists
        if (pat2str.count(c)) {
            string str = pat2str[c];
            // then check if we can use it to match str[i...i+s.length()]
            // if it can match, great, continue to match the rest
            return s.substr(i, str.length()) == str && isMatch(s, pattern, i + str.length(), j + 1);
        }
        
        // pattern char doesn't exits in the map
        for (int k = i; k < s.length(); ++k) {
            string str = s.substr(i, k - i + 1);
            
            // this string already mapped to some other pattern char
            if (strSet.count(str))
                continue;
            
            // create or update it
            pat2str.insert({c, str});
            strSet.insert(str);
            
            // continue to match the rest
            if (isMatch(s, pattern, k + 1, j + 1))
                return true;
            
            // backtracking
            pat2str.erase(c);
            strSet.erase(str);
        }
        return false;
    }
};
