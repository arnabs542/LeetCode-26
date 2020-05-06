/* Bruce Force approach: Create all substring - O(n^2)
Now iterate once and check if the substring is palindrome.
Then return the largest palidromic substring- O(n^3)
*/


/* Expand Around Center approach:
Two cases:
a.  "racecar"
b.  "aabbaa"

Time: O(n^2)
Space: O(1)
*/


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1)
            return "";

        int start = 0;
        int end = 0;

        for (int i=0; i<s.length(); i++){
            // racecar
            int len1 = expandFromMiddle(s,i,i);
            // aabbaa
            int len2 = expandFromMiddle(s,i,i+1);
            int len = max(len1,len2);
            if (len > end - start + 1){
                start = i - (len-1)/2;
                end = i + len/2 ;
            }

        }
        return s.substr(start,end-start+1);

    }
private:
    int expandFromMiddle(string s, int left, int right){
        if (left > right){
            return 0;
        }

        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
        // -1 because left and right both moves one pos extra.
    }
};
