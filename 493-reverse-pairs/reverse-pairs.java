class Solution {
    public int reversePairs(int[] nums) {
        long[] longNums = new long[nums.length];
        for (int i = 0; i < nums.length; i++) {
            longNums[i] = nums[i];
        }
        
        int count = mergeSort(longNums, 0, longNums.length - 1);
        // System.out.println(Arrays.toString(nums));
        return count;
    }

    static int mergeSort(long arr[], int low, int high) {
        int count = 0;
        if (low >= high) return 0;

        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += checkPair(arr, low, mid, high);
        merge(arr, low, mid, high);

        return count;
    }

    static int checkPair(long arr[], int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2 * arr[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        return count;
    }

    static void merge(long arr[], int low, int mid, int high) {
        int s1 = mid - low + 1;
        int s2 = high - mid;

        long a1[] = new long[s1];
        long a2[] = new long[s2];

        for (int i = 0; i < s1; i++) {
            a1[i] = arr[low + i];
        }
        for (int i = 0; i < s2; i++) {
            a2[i] = arr[mid + 1 + i];
        }

        int p = 0, q = 0, k = low;
        while (p < s1 && q < s2) {
            if (a1[p] < a2[q]) {
                arr[k] = a1[p];
                p++; k++;
            } else {
                arr[k] = a2[q];
                q++; k++;
            }
        }

        while (p < s1) {
            arr[k] = a1[p];
            p++; k++;
        }
        while (q < s2) {
            arr[k] = a2[q];
            q++; k++;
        }
    }
}