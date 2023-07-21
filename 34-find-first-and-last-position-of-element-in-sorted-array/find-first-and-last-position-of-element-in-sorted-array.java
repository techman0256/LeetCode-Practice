class Solution {
    public int[] searchRange(int[] arr, int target) {
        int n = arr.length;

        int left = 0, right = n - 1;
        int low = -1, high = -1;

        while (left <= right) {
            int mid = left + (right - left) /2;
            if (arr[mid] == target) {
                low = mid;
                right = mid - 1;
            }

            if (arr[mid] < target) {
                left = mid + 1;

            } else if (arr[mid] > target) {
                right = mid - 1;
            }
        }
    
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + ((right - left)/2);
        
            if (arr[mid] == target) {
                high = mid;
                left = mid + 1;
               
            }

            if (arr[mid] < target) {
                left = mid + 1;

            } else if (arr[mid] > target) {
                right = mid - 1;
            }
        }

        return new int[] {low, high};
    }
}