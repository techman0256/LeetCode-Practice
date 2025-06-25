class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int max_length = 1;
        int start = 0;
        // int end = 0;

        for (int i=0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                int left = i + 1;
                int right = j - 1;
                
                dp[i][j] = s[i] == s[j];
                if (left <= right) {
                    dp[i][j] = dp[i][j] && dp[left][right];
                }

                if (dp[i][j] == true && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    start = i; 
                    // end = j;
                }
            }
        }

        // for (int i=0; i < n; i++) {
        //     for (int j=0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << max_length << " start is this " << start << endl;
        return s.substr(start, max_length);
    }
};