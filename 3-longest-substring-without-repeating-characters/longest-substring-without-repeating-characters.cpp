class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MIN;
        map<char, int> mpp;
        int start = 0, end = 0;
        while (end < n) {

            while (end < n && mpp.find(s[end]) == mpp.end()) {
                // cout << bool(mpp.find(s[end]) == mpp.end()) << endl;
                mpp[s[end]] = 1;
                end ++;
                ans = max(ans, end - start);

                cout << start << " " << end << endl;
            }

            while (start <= end && mpp.find(s[end]) != mpp.end()) {
                mpp.erase(s[start]);
                start ++;
                cout << start << " " << end << endl;
            }
        }
        
        
        return ans;

    }
};