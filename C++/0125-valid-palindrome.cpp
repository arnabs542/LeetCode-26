// Time O(n)
// Space O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        //auto right = prev(s.end());
        auto right = --s.end();

        while (left < right){
            while (left<right && !isalnum(*left)){
                ++left;
            }
            while (left<right && !isalnum(*right)){
                --right;
            }
            if (tolower(*left) != tolower(*right)){
                return false;
            }
            ++left, --right;
        }
        return true;



    }
};
