// Tags: Binary-search String Google
// Time:  O(n + logm), n is the length of text, m is the number of fonts
// Space: O(1)
class Solution {
    bool check(vector<int>& cnt, int w, int h, vector<int>& fonts, FontInfo fontInfo, int x) {
        if (fontInfo.getHeight(fonts[x]) > h)
            return false;
        int width = 0;
        for (int i = 0; i < 26; ++i) {
            width += cnt[i]*fontInfo.getWidth(fonts[x], 'a' + i);
            if (width > w)
                return false;
        }
        return true; 
    }
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int left = 0, right = fonts.size() - 1;
        int ans = -1;
        vector<int> cnt(26);
        for (char c : text)
            ++cnt[c - 'a'];
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (check(cnt, w, h, fonts, fontInfo, mid)) {
                ans = fonts[mid];
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};
