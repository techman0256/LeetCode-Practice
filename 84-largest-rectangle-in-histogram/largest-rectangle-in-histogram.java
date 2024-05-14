class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;

        int lse[] = new int[n];
        int rse[] = new int[n];

        Stack<Integer> stk = new Stack<Integer>();
        
        
        for (int i=0; i < n; i++) {
            while (!stk.isEmpty() && heights[i] <= heights[stk.peek()]) {
                stk.pop();
            }

            if (stk.isEmpty()) lse[i] = 0;
            else lse[i] = stk.peek() + 1;

            stk.push(i);
        }

        stk.clear();

        for (int i=n - 1; i >= 0; i--) {
            while (!stk.isEmpty() && heights[i] <= heights[stk.peek()]) {
                stk.pop();
            }

            if (stk.isEmpty()) rse[i] = n - 1;
            else rse[i] = stk.peek() - 1;

            stk.push(i);
        }

        int area = Integer.MIN_VALUE;
        for (int i=0; i < n; i++) {
            area = Math.max( area, (rse[i] - lse[i] + 1)  * heights[i] );
        }

        System.out.println(Arrays.toString(lse));
        System.out.println(Arrays.toString(rse));


        return area;
    }
}