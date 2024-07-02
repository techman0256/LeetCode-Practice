class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int left = -1 , right = n - 1;
        while ( left + 1 < right ) {
            int mid = (left + right) / 2;
            if (arr[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (arr[right] == target)
            return right;
        else return -1;
    }
};