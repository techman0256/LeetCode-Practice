class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int left = 0, right = n - 1;

        while ( left <= right ) {
            int mid = (left + right) /2;
            if (arr[mid] == target) return mid;

            if (arr[left] <= arr[mid]) {
                if (arr[left] <= target && target < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (arr[mid] < target && target <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } 
        }

        return -1;
    }
};