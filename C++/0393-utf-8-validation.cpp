// Tags: Bit-manipulation Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        // number of bytes to be followed with most significant 2 bits being 10
        int count = 0;
        for (int byte : data) {
            if (count == 0) {
                // start of new utf-8 char
                if (byte >> 5 == 0b110)
                    count = 1;
                else if (byte >> 4 == 0b1110)
                    count = 2;
                else if (byte >> 3 == 0b11110)
                    count = 3;
                else if (byte >> 7) // most significant bit is not zero
                    return false;
            } else {
                if (byte >> 6 != 0b10)
                    return false;
                // a following byte observed
                --count;
            }
        }
        // all following bytes observed for the last utf-8 char
        return count == 0;
    }
};
