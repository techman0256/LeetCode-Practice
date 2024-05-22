class Solution {
    public int trap(int[] height) {
        int n = height.length;
        Stack<Integer> stk = new Stack<Integer>();
        
        int front[] = new int[n];
        int back[] = new int[n];
        for (int i=n - 1; i >=0; i--) {
            while(!stk.isEmpty() && stk.peek() <= height[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                front[i] = -1;
                stk.push(height[i]);
            } else {
                front[i] = stk.peek();
            }
        }

        stk.clear();

        for (int i=0; i < n; i++) {
            while(!stk.isEmpty() && stk.peek() <= height[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                back[i] = -1;
            stk.push(height[i]);
            } else {
                back[i] = stk.peek();
            }
        }
        int cnt = 0;
     
        for (int i=0; i < n; i++) {
            if (front[i] != -1 && back[i] != -1) {
                cnt += Math.min(front[i], back[i]) - height[i];
            }
        }

        return cnt;
    }
}