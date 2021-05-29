// Tags: Brainteaser Google
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool canTransform(string start, string end) {
        // we already know start.length() == end.length()
        // index, char
        vector<pair<int, char>> pstart, pend;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] != 'X')
                pstart.push_back({i, start[i]});
            if (end[i] != 'X')
                pend.push_back({i, end[i]});
        }
        // the number of X positions should be same in both strings
        if (pstart.size() != pend.size())
            return false;
        // check each pair (a char in start with corresponding char in end)
        for (int i = 0; i < pstart.size(); ++i) {
            if (pstart[i].second != pend[i].second)
                return false;
            if (pstart[i].second == 'L') {
                // for each position (j, k) of paired 'L' character in both strings,
                // j should be either
                // = k : 'XL' in both
                // > k : 'XL' in start and 'LX' in end
                if (pstart[i].first < pend[i].first)
                    return false;
            } else {
                // for each position (j, k) of paired 'R' character in both strings,
                // j should be either
                // = k : 'RX' in both
                // < k : 'RX' in start and 'XR' in end
                if (pstart[i].first > pend[i].first)
                    return false;
            }
        }
        return true;
    }
};
/*
Special case:
start = "XXXXXLXXXX"
end = "LXXXXXXXXX"
ans = true
*/
