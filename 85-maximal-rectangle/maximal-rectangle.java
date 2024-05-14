class Solution {
    public int maximalRectangle(char[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;

        int hists[] = new int[col];
        int ans = Integer.MIN_VALUE;

        for (int i=0; i < row; i++) {
            for (int j=0; j < col; j++) {
                hists[j] = matrix[i][j] == '0' ? 0 : hists[j] + 1;
            }

            // System.out.println(Arrays.toString(hists));

            Stack<Integer> stk = new Stack<Integer>();

            for (int j=0; j <= col; j++) {
                while (!stk.isEmpty() && (j == col || hists[j] < hists[stk.peek()])) {
                    int top = stk.pop();

                    int width = 0;
                    if (stk.isEmpty()) width = j;
                    else width = j - stk.peek() - 1;

                    ans = Math.max(ans, hists[top] * width); 
                }
                stk.push(j);
            }
        }

        return ans;
    }
}