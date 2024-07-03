class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int left = 0, right = n - 1;
        while ( left <= right ) {
            int mid = (left + right) /2;

            if ( arr[mid] - mid - 1 < k ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << left << " " << right << endl;
        int missing_cnt = 0;
        int missing = 0; 
        if (left == n) {
            missing_cnt = arr[right] - right - 1;
            missing = arr[right];
            while (missing_cnt != k) {
                missing++;
                missing_cnt++;
            }
        } else {
            // cout << " hi " << endl;
            missing_cnt = arr[left] - left - 1;
            missing = arr[left];
            // cout << missing_cnt << " " << k << endl;
            while (missing_cnt != k - 1) {
                cout << missing << endl;
                missing--;
                missing_cnt--;
            }
        }
        
        // arr[left];
        

        return missing;
    }
};