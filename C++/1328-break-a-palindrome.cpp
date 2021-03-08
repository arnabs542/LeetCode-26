// Tags: String Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        for (int i = 0; i < n/2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // if non-a char wasn't found in first half,
        // it means all char's in first half were 'a'
        // and since it is a palindrome, as char's in the second
        // half will also be 'a' (except middle char if n is odd)
        // => replace last char with 'b' to get lexicographically
        //    smallest string.
        palindrome[n - 1] = 'b';
        return n < 2 ? "" : palindrome;
    }
};
/*
Check half of the string, replace a non 'a' character to 'a'.
If non 'a character not found, replace the last character to 'b'

If only one character, return empty string.
*/
