// Tags: Amazon Math String
// Time: O(n/3)
// Space: O(n/3)
class Solution {
    vector<string> upto19 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        return helper(num);
    }
    string helper(int num) {
        string ret;
        if (num < 20)
            ret = upto19[num];
        else if (num < 100)
            ret = tens[num/10] + " " + upto19[num%10];
        else if (num < 1000)
            ret = upto19[num/100] + " Hundred " + helper(num%100);
        else if (num < 1000000)
            ret = helper(num/1000) + " Thousand " + helper(num%1000);
        else if (num < 1000000000)
            ret = helper(num/1000000) + " Million " + helper(num%1000000);
        else if (num < 1000000000000)
            ret = helper(num/1000000000) + " Billion " + helper(num%1000000000);
        
        // trim leading and training whitespaces at each function call
        ret = ret.back() == ' ' ? ret.substr(0, ret.size() - 1) : ret;
        ret = ret.front() == ' ' ? ret.substr(1) : ret;
        return ret;
    }
};
