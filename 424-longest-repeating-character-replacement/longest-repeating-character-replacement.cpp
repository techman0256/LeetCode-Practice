class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int start = 0, end = 0;
        map<char, int> mpp;
        char freq = 'a';
        int win = INT_MIN;

        while (end < n) {

            mpp[s[end]] += 1;
            cout << end << " " << start << " " << mpp[freq] << endl;
            if (mpp[s[end]] > mpp[freq]) {
                freq = s[end];
                cout << freq << " reset to" << endl;
            }

            if (end - start + 1 - mpp[freq] > k) {
                cout << end << " " << start << " shrinkied " << mpp[freq] << endl;
                mpp[s[start]] -= 1;
                start ++;
            } else {
                win = max(win, end - start + 1);

            }
            end ++;
        }

        return win;

    }
};