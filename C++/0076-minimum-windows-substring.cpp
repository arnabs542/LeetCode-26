// Tags: Sliding-window String Hash-table Amazon
// Time O(n)
// Space O(k)
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.length() < t.length())
            return "";

        const int ASCII_MAX = 256;
        // char to count
        vector<int> exp_cnt(ASCII_MAX,0);
        vector<int> cur_cnt(ASCII_MAX,0);

        int left = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for(const auto &c : t){
            exp_cnt[c]++;
        }

        // number of chars of t which have been seen in s
        int count = 0;

        for (int right=0; right < s.length(); right++){
            cur_cnt[s[right]]++;
            // keep increasing window until count becomes t.length()
            if ( cur_cnt[s[right]] <= exp_cnt[s[right]]){
                // (once count reaches t.length(), this will not be executed
                // again)
                count++;
            }

            if (count == t.length()){
                // all chars of t have been seen in s

                // remove unnecessary chars from left
                while (exp_cnt[s[left]]==0 || cur_cnt[s[left]] >  exp_cnt[s[left]]){
                    cur_cnt[s[left]]--;
                    left++;
                }

                if (right-left+1 < min_width){
                    min_width = right-left+1;
                    min_start = left;
                }

            }

        }


        if (min_width == numeric_limits<int>::max()){
            return "";
        }

        return s.substr(min_start, min_width);
    }
};
