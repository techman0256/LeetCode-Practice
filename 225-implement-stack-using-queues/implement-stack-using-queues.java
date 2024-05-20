class MyStack {
    Queue<Integer> q1;
    public MyStack() {
        q1 = new LinkedList<Integer>();
        // q2 = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        q1.add(x);
    }
    
    public int pop() {
        int num = q1.poll();
        for (int i=0; i < q1.size(); i++) {
            q1.add(num);
            // System.out.println()
            num = q1.poll();
        }

        return num;
    }
    
    public int top() {
        int num = q1.poll();
        for (int i=0; i < q1.size() ; i++) {
            q1.add(num);
            num = q1.poll();
        }
        q1.add(num);
        return num;
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */