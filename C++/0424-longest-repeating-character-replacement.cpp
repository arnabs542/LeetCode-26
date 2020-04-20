// Time O(n)
// Space O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int result = 0, maxCount = 0;

        for(int left=0, right=0; right < s.length(); right++){
            ++count[s[right]];
            maxCount = max(maxCount, count[s[right]]);

            while (right-left+1 - maxCount > k){
                --count[s[left]];
                left++;
            }

            result = max(result, right-left+1);
        }
        return result;

    }
};
