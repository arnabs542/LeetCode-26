// Tags: Greedy Array
// Time:  O(n)
// Space: O(26) = O(1)
// Check Python version for comments
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> char_map(26);
        for (char c: tasks)
            ++char_map[c - 'A'];
        sort(char_map.begin(), char_map.end(), greater<int>());
        int max_val = char_map[0] - 1;
        int idle_slots = max_val*n;
        for (int i = 1; i < 26; ++i)
            idle_slots -= min(max_val, char_map[i]);
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};
