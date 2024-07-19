class Solution {
public:
    void computeLPS(string needle, vector<int> &LPS){
        if (needle == "") {
            return;
        }

        int prevLPS = 0;
        int i = 1;
        while (i < needle.length()) {
            if (needle[i] == needle[prevLPS]) {
                LPS[i] = prevLPS + 1;
                prevLPS += 1;
                i++;
            } else if (prevLPS == 0) {
                LPS[i] = 0;
                i++;
            } else {
                prevLPS = LPS[prevLPS - 1];
            }

        }
        

    }
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        vector<int> LPS(m, 0);
        computeLPS(needle, LPS);

        int i = 0, j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = LPS[j - 1];
                }
            }

            if (j == m) {
                return i - m;
            }
        }

        return -1;
    }
};