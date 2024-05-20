class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> stk = new Stack<Character>();
        
        for (int i=0; i < n; i++) {
            char now = s.charAt(i);
            if (now == '(' || now == '{' || now == '[') {
                stk.push(now);
            } else {
                if (stk.isEmpty()) {
                    return false;
                }
                int peek = stk.peek();
                if (!(now == ')' && peek == '(' ) && !(now == '}' && peek == '{') && !(now == ']' && peek =='[') ) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }

        // if (stk.)

        return stk.isEmpty();
    }
}