class Solution {
public:
    long long nCr(long long n, long long r){
        if(r > n - r) r = n - r;
        long long ans = 1;
        long long i;
        for(i = 1; i <= r; i++) {
            ans *= (n - r + i);
            ans /= i;
        }
        return ans;
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {   
        long long H = destination[1];
        long long V = destination[0];
        long long  n = H + V;

        string ans = "";

        while ( H > 0 && V > 0 ) {
            long long mid = nCr(n - 1, H - 1);

            // cout << mid << endl;
            if (mid < k) {
                ans += 'V';
                V--;
                k -= mid;
            } else {
                ans += 'H';
                H--;
            }
            n--;
        }

        while (H > 0) {
            ans += 'H';
            H--;
        }

        while (V > 0) {
            ans += 'V';
            V--;
        }

        return ans;        
    }
};