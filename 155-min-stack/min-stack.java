class MinStack {
    Stack<Long> stk;
    Long min;

    public MinStack() {
        stk = new Stack<Long>();
        min = Long.MAX_VALUE;
    }
    
    public void push(int val) {
        Long value = Long.valueOf(val);
        if (stk.isEmpty()) {
            min = value;
            stk.push(value);
        } else {
            if (value < min) {
                stk.push(2 * value - min);
                min = value;
            } else {
                stk.push(value);
            }
        }
        
    }
    
    public void pop() {
        if (stk.isEmpty()) return;

        if (stk.peek() < min) {
            min = 2 * min - stk.peek();
        }
        stk.pop();
    }
    
    public int top() {
        Long ans;
        if (stk.peek() < min) {
            ans = min;
            // min = 2 * min - stk.peek();
        } else {
            ans = stk.peek();
        }


        return ans.intValue();
    }
    
    public int getMin() {
        return min.intValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */