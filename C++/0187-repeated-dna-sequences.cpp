// Tags: Hash-table Bit-manipulation Amazon
// Time: O(l*(n-l)), l = 10, O(l) to create a substring of length l
// Space: O(l*(n-l)), to keep hashset
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};
        unordered_set<string> seen, repeated;
        for (int i = 0; i <= s.length() - 10; ++i) {
            string dna = s.substr(i, 10);
            if (seen.count(dna))
                repeated.insert(dna);
            seen.insert(dna);
        }
        // or
        // vector<string> res(repeated.size());
        // copy(repeated.begin(), repeated.end(), res.begin());
        // or
        // vector<string> res;
        // copy(repeated.begin(), repeated.end(), back_inserter(res));
        return vector<string>(repeated.begin(), repeated.end());
    }
};




class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};
        unordered_map<char, int> to_int {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        
        // convert string to an array of integers
        vector<int> nums(s.length());
        for (int i = 0; i < s.length(); ++i)
            nums[i] = to_int[s[i]];
        
        int bitmask = 0;
        unordered_set<int> seen, repeated;
        // i denotes start integer of a dna seq
        for (int i = 0; i < nums.size() - 10 + 1; ++i) {
            if (i == 0) {
                // compute hash of the first sequence in O(l) time
                for (int j = 0; j < 10; ++j) {
                    bitmask <<= 2;
                    bitmask |= nums[i];
                }
            } else {
                bitmask <= 2;
                bitmask |= nums[i + 10 - 1];
                bitmask &= ~(3 << 2*10);
            }
        }
        
        if (seen.count(bitmask))
            repeated.insert(bitmask);
    }
};
/*
Let's start from conversion of string to 2-bits integer array
A = 00, C = 01, G = 10, T = 11
Now each bitmask after the first one could be computed in O(1) time:
* Do left shift to free the last two bits:
    bitmask <<= 2
* Save current digit in these last two bits: 
    bitmask |= nums[i]
* Unset the first two bits: 2l bit and (2l + 1) bit
    bitmask & ~(3 << 2l)
    (2l as each integer is represented by two bits)
*/
