#define mod 1000000007

class Solution {
public:
    long long power(long long base, long long exp) {
        if (exp == 0) {
            return 1;
        }
        if (exp == 1) {
            return base % mod;
        }

        long long t = power(base, exp / 2);
        t = (t * t)  % mod;

        if (exp % 2 == 0) {
            return t;
        } else {
            return ((base % mod) * t) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even, prime;
        long long cnt = 0;
        if (n & 1 == 1) {
            even = (n / 2) + 1;
            prime = (n / 2);
        } else {
            even = n /2;
            prime = n /2;
        }

        cnt = ( (power(5, even) % mod) * (power(4, prime) % mod) ) % mod;

        return (int)cnt; 
    }
};