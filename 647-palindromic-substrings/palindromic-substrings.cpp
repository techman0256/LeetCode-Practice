class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool> (n, 0));
        for (int i=0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i=n - 2; i >= 0; i--) {
            for (int j=n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1;
                }
                int left = i + 1;
                int right = j - 1;
                if (left <= right) {
                    dp[i][j] = dp[i][j] && dp[left][right];
                }
            }
        }
        int answer = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                answer += dp[i][j];
            }
        }

        return answer;
    }
};