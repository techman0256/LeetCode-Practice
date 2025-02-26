class Solution {
public:
    // Precomputed small binomials modulo 5 for 0 <= n,k < 5.
    // Note: row 4 is {1, 4, 6, 4, 1} but 6 mod 5 = 1.
    int binom_small[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 2, 1, 0, 0},
        {1, 3, 3, 1, 0},
        {1, 4, 1, 4, 1}
    };

    // Lucas theorem for p = 5.
    // Returns binom(n, k) mod 5.
    int lucas_mod5(int n, int k) {
        int res = 1;
        while(n > 0 || k > 0) {
            int n_d = n % 5;
            int k_d = k % 5;
            if(k_d > n_d) return 0;
            res = (res * binom_small[n_d][k_d]) % 5;
            n /= 5;
            k /= 5;
        }
        return res;
    }
    
    // Binom(n, k) mod 2: it is 1 if and only if each bit set in k is also set in n.
    int binom_mod2(int n, int k) {
        if ((k & ~n) != 0)
            return 0;
        return 1;
    }
    
    // Combine the results modulo 2 and modulo 5 using CRT.
    // We need x mod 10 such that:
    //    x ≡ mod2 (mod 2)
    //    x ≡ mod5 (mod 5)
    int binom_mod10(int n, int k) {
        int r2 = binom_mod2(n, k);   // 0 or 1.
        int r5 = lucas_mod5(n, k);    // 0,1,2,3,4.
        for (int x = 0; x < 10; x++) {
            if (x % 2 == r2 && x % 5 == r5)
                return x;
        }
        return -1; // Should never happen.
    }
    
    bool hasSameDigits(string s) {
        int n = s.size();
        // According to constraints, n is between 3 and 1e5.
        int m = n - 2;  // We'll need the coefficients for (1+x)^(n-2)
        long long X = 0, Y = 0;
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
        }
        // Compute the final two digits as weighted sums.
        // X = sum_{j=0}^{m} binom(m, j) * a[j] mod 10.
        // Y = sum_{j=0}^{m} binom(m, j) * a[j+1] mod 10.
        for (int j = 0; j <= m; j++) {
            int coeff = binom_mod10(m, j);
            X = (X + (long long)coeff * digits[j]) % 10;
            Y = (Y + (long long)coeff * digits[j+1]) % 10;
        }
        return X == Y;
    }
};