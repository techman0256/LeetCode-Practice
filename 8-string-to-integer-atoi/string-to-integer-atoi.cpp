class Solution {
public:
    int convert(int idx, string s, int number, int sign) {
    
        if ( idx == s.length() || !(s[idx] >= '0' && s[idx] <= '9') ) {
            return number * sign;
        }
        int digit = s[idx] - '0';
        
        if ( number > (INT_MAX - digit)/10 ) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        number = (number * 10) + digit;
        // cout << number << endl;
        number = convert(idx + 1, s, number, sign);

        return number;        
    }
    int myAtoi(string s) {
        int idx = 0;
        while (s[idx] == ' ') {
            idx++;
        }

        int sign = 0;
        int ans = 0;
        if (s[idx] == '-') {
            sign = -1;
            idx++;
        } else {
            sign = 1;
            if (s[idx] == '+') idx++;
        }
        // cout << sign << " " << idx << " idx" << endl;

        int number = 0;
        number = convert(idx, s, 0, sign);

        // if (number == INT_MAX && sign == -1) {
        //     return INT_MIN;
        // }

        return number;

    }
};