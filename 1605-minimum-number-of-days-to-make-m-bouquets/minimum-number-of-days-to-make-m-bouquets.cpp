// #define long long int long long int
class Solution {
public:
    bool makeBouquets(long long int day, long long int m, long long int k, vector<int> &bloomDay) {
        int n = bloomDay.size();
        int i = 0;
        while ( i < n ) {
            long long int adj = 0;
            while (i < n && bloomDay[i] <= day) {
                // cout << "hi  " << i << endl;
                adj++;
                i++;
                if (adj == k) {
                    i--;
                    break;
                }
            }
            // cout << "adj " << adj << endl;
            if (adj == k) {
                m -= 1;
                if (m == 0) break;
            }
            i++;
        }
        cout << m << endl;
        return m == 0;        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n = bloomDay.size();
        long long int ans = INT_MAX;
        if (n <  (long long int)m * (long long int)k) return -1;

        long long int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());

        while ( left <= right ) {
            long long int mid = (left + right) /2;
            // cout << mid << " " << makeBouquets(mid, m, k, bloomDay) << endl;
            if ( makeBouquets(mid, (long long int)m, (long long int)k, bloomDay) ) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (ans == INT_MAX) return -1;
        return ans;


    }
};