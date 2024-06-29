class Solution {
public:
    bool isUgly(int n) {
        // cout << -6 % 2 << endl;

        if (n == 1 || n == 0) {
            return n;
        }
        if (n < 0) {
            return false;
        }

        while (n != 1 && n % 2 == 0) {
            n = n / 2;
        }
        while (n != 1 && n % 3 == 0) {
            n = n / 3;
        }
        while (n != 1 && n % 5 == 0) {
            n = n / 5;
        }


        if (n == 1) {
            return true;
        }
        return false;
    }
};