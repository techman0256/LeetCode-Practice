class Solution {
public:
    int nthUglyNumber(int n) {
        int primes[] = {2, 3, 5};
        // int pointers[] = {0, 0, 0};
        int two = 0;
        int three = 0;
        int five = 0;

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i=1; i < n; i++) {
            dp[i] = min(2 * dp[two], min(3 * dp[three], 5 * dp[five]));
            
            if (dp[i] == 2 * dp[two]) {
                two++;
            }
            if (dp[i] == 3 * dp[three]) {
                three++;
            }
            if (dp[i] == 5 * dp[five]) {
                five++;
            }
        }

        return dp[n - 1];

    }
};