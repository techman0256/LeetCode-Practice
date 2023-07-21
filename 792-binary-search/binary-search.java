class Solution {
    public int search(int[] arr, int k) {
        int n = arr.length;

        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (arr[mid] == k) {
                return mid;
            }
            
            if (arr[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return -1;
        
    }
}