// Tags: Amazon Array
// Time: O(n)
// Space: O(1)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<int, char> res {releaseTimes[0], keysPressed[0]};
        
        for (int i = 1; i < keysPressed.length(); ++i) {
            if (releaseTimes[i] - releaseTimes[i-1] > res.first)
                res = make_pair(releaseTimes[i] - releaseTimes[i-1], keysPressed[i]);
            else if (releaseTimes[i] - releaseTimes[i-1] == res.first)
                res.second = max(keysPressed[i], res.second);
        }
        return res.second;
    }
};
