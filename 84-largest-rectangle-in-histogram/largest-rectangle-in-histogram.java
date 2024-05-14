class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;

        int area = 0;

        Stack<Integer> stk = new Stack<Integer>();

        for (int i=0; i <= n; i++) {
            while (!stk.isEmpty() && (i==heights.length || heights[i] < heights[stk.peek()]) ) {
                int top = stk.pop();
                
                int width = 0;
                if (stk.isEmpty()) width = i;
                else width = i - stk.peek() - 1;
                area = Math.max(area, width * heights[top]);
            }

            stk.push(i);
        }

        return area;
        
    }
}