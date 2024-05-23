class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;

        int lse[] = new int[n];
        int rse[] = new int[n];

        Stack<Integer> stk = new Stack<Integer>();

        for (int i=0; i < n; i++) {
            while (!stk.isEmpty() && arr[stk.peek()] > arr[i]) {
                stk.pop();
            }     

            if (stk.isEmpty()) {
                lse[i] = -1;
            } else {
                lse[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();

        for (int i=n - 1; i >= 0; i--) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }     

            if (stk.isEmpty()) {
                rse[i] = n;
            } else {
                rse[i] = stk.peek();
            }
            stk.push(i);
        }

        System.out.println(Arrays.toString(lse));
        System.out.println(Arrays.toString(rse));

        long cnt = 0;
        long mod = 1000000007;
        for (int i=0; i < n; i++) {
            int times = (rse[i] - i) * (i - lse[i]);
            cnt = ((cnt % mod) + ((arr[i] % mod) * (times % mod)) % mod ) % mod;
            // cnt %= mod;
        }

        return (int)cnt;
    }
}