// Time O(n)
// Space O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int result = 0, maxCount = 0;

        // we are only interested in the longest valid substring,
        // our sliding windows need not shrink, even if a window may
        // cover an invalid substring
        for(int left=0, right=0; right < s.length(); right++){
            ++count[s[right]];
            // max count for any char in the window
            maxCount = max(maxCount, count[s[right]]);

            // window length - max count seen so far > k
            while (right-left+1 - maxCount > k){
                --count[s[left]];
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};
