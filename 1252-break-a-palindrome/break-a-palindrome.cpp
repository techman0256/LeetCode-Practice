class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }


        int idx = 0;
        while (idx < n / 2 && palindrome[idx] == 'a') {
            idx++;
        }

        // if (idx == (n / 2) && n % 2 == 1 ) {
        //     palindrome[idx + 1] = 'b';
        // } 
        if (idx >= n / 2) {
            palindrome[n - 1] = 'b';
        }
        else {
            palindrome[idx] = 'a';
        }


        return palindrome;
    }
};