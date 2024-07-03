class Solution {
public:
    long long int calculateEat(int k, vector<int> &piles) {
        int n = piles.size();
        long long int hours = 0;
        for (int i=0; i < n; i++) {
            hours += ( (long)piles[i] / k ) + (int)( (long)piles[i] % k != 0);
        }
        // cout << hours << endl;

        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();        
        long long int ans = INT_MAX;

        long long int left = 1, right = *max_element(piles.begin(), piles.end());
        

        while ( left <= right ) {
            long long int mid = (left + right) /2;

            if ( calculateEat(mid, piles) <= h ) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        return (int)ans;

    }
};