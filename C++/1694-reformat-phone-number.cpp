// Tags: String WC220
// Time: O(n)
// Space: O(n)
class Solution {
    string format(string number) {
        if (number.size() >= 4) {
            int take = number.size() > 4 ? 3 : 2;
            return number.substr(0, take) + "-" + format(number.substr(take));
        }
        return number;
    }
public:
    string reformatNumber(string number) {
        auto end_it = copy_if(number.begin(), number.end(), number.begin(), [](char c){return isdigit(c);});
        // creating temporary string using string constructor
        return format(string(number.begin(), end_it));
    }
};
