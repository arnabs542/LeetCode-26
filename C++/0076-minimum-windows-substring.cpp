// Time O(n)
// Space O(k)
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.length() < t.length())
            return "";

        const int ASCII_MAX = 256;

        vector<int> exp_cnt(ASCII_MAX,0);
        vector<int> cur_cnt(ASCII_MAX,0);

        int count = 0;
        int left = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for(const auto &c : t){
            exp_cnt[c]++;
        }

        for (int right=0; right < s.length(); right++){
            cur_cnt[s[right]]++;

            if ( cur_cnt[s[right]] <= exp_cnt[s[right]]){
                count++;
            }

            if (count == t.length()){
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
