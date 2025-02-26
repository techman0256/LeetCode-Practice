class Solution {
public:
    string reduce(string& s) {
        if (s.length() == 2) return s;
        
        string ops = "";
        int n = s.length();
        
        for (int i = 1; i < n; i++) {
            int digit1 = s[i] - '0';
            int digit2 = s[i - 1] - '0';
            ops += to_string((digit1 + digit2) % 10);
        }
        
        return reduce(ops);
    }
    
    bool hasSameDigits(string s) {
        string result = reduce(s);
        return result[0] == result[1];
    }
};
