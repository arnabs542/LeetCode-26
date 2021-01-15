// Tags: WC215 Greedy
// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        vector<int> cnt1(26);
        vector<int> cnt2(26);
        for (auto i = 0; i < word1.size(); ++i) {
            ++cnt1[word1[i] - 'a'];
            ++cnt2[word2[i] - 'a'];
        }
        
        // Both string have the same set of characters
        if (!equal(cnt1.begin(), cnt1.end(), cnt2.begin(), cnt2.end(), [] (int a, int b) {
            return (bool)a == (bool)b;}))
            return false;
        // O(26log26) ~ O(1)
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        // Both string have the same frequency of characters
        return cnt1 == cnt2;
    }
};
/*
We need to check that
    Both string have the same set of characters.
    Both string have the same frequency of characters.
E.g string "abbccddd" has [1, 2, 2, 3] char frequency, and so does "bddccaaa".
*/
