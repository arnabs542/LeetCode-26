// Tags: Sliding-window String Hash-table Amazon
// Time O(n)
// Space O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // records the last known index of each char
        unordered_map<char,int> lookup;
        int result = 0;
        for (int left = 0, right = 0; right < s.length(); ++right){
            if (lookup.count(s[right])){
                // max ensures left pointer either stays where it is
                // or shifted to right but never moves back to left
                // e.g "abba"
                left = max(left, lookup[s[right]] + 1);
            }
            lookup[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
};
