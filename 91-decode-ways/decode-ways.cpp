class Solution {
public:
    int decodeWays(int idx, string s, int carry, vector<vector<int>> &dp) {
        if (idx == s.length() && carry == 0) {
            return 1;
        }
        if (idx == s.length() && carry != 0) return 0;

        if (dp[idx][carry] != INT_MAX) return dp[idx][carry];
        int digit = s[idx] - '0';
        if (digit > 6 && carry == 2) return 0;
        if (digit == 0 && carry == 0) return 0;

        int ans = 0;
        if (digit <= 2 && carry == 0) {
            ans += decodeWays(idx + 1, s, digit, dp);
        }
        ans += decodeWays(idx + 1, s, 0, dp);
        
        dp[idx][carry] = ans;
        return ans;
    }
    int numDecodings(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        if (s[0] == '0') return 0;
        return decodeWays(0, s, 0, dp);
    }
};