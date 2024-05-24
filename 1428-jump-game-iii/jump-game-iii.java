class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean visited[] = new boolean[n + 1];
        boolean dp[] = new boolean[n + 1];
        return isPitfall(arr, start, visited, dp);
    }
    static boolean isPitfall(int[] arr, int start, boolean visited[], boolean dp[]) {
        if (start < 0 || start >= arr.length) return false;
        if (visited[start] == true) return dp[start];
        if (arr[start] == 0) return true;

        visited[start] = true;

        return dp[start] = isPitfall(arr, start - arr[start], visited, dp) || isPitfall(arr, start + arr[start], visited, dp);

    }
}