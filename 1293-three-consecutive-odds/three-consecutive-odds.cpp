class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        int cnt = 0;

        for (int i=0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                cnt = 0;
                odd = 0;
            } else {
                cnt++;
                odd = 1;
                if (cnt == 3 && odd == 1) {
                    return true;
                }
            }
        }

        return false;
    }
};