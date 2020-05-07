// DP Solution
// Time O(n^2)
// Space O(n^2)
class Solution {
public:
    int countSubstrings(string s) {

        if (s.length()<=1)
            return s.length();

        bool opt[s.length()][s.length()];
        // vector<vector<bool>> dp(n,vector<bool>(n, false));

        int count = 0;

        int n = s.length();


        for (int i = n - 1; i >= 0 ; i--){
            count++;
            opt[i][i] = 1;
            for (int j = i + 1; j < n; j++){
                opt[i][j] = (s[i]==s[j]) && (j - i == 1 || opt[i+1][j-1]);
                if (opt[i][j])
                    count++;
            }
        }

        return count;
    }
};
