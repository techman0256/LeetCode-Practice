class Solution {
public:
    double myPow(double base, int exp) {
        if (exp == 0) {
            return 1;
        }
        if (exp == 1) {
            return base;
        }

        double t = myPow(base, abs(exp / 2));
        t = (t * t);
        if (exp < 0) {
            t = 1 / t;
        } 
        // else {
        // }

        if (exp % 2 == 0) {
            return t;
        } else {
            if (exp > 0) {
                return base * t ;
            } else {
                return (1 / base) * t;
            }
        }
    }
};
