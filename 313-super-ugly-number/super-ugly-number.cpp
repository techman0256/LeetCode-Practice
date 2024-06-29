class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pointers(primes.size(), 0);
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i=1; i < n; i++) {
            long mini = INT_MAX;
            for ( int j=0; j < primes.size(); j++ ) {
                mini = min(mini, ((long)primes[j] * dp[pointers[j]]));
            }
            for ( int j=0; j < primes.size(); j++ ) {
                if (mini == ((long)primes[j] * dp[pointers[j]])) {
                    pointers[j] ++;
                }
            }
            dp[i] = mini;
            
           
        }

        return dp[n - 1];
    }
};