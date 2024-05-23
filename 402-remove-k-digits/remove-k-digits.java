class Solution {
    public String removeKdigits(String num, int k) {
        int n= num.length();

        Stack<Integer> stk = new Stack<Integer>();
        

        for (int i=0; i < n; i++) {
            while (!stk.isEmpty() && k > 0  && num.charAt(i) - '0' < stk.peek()) {
                stk.pop();
                k--;
            }

            stk.push(num.charAt(i) - '0');
        }
        
        while (!stk.isEmpty() && k > 0) {
            stk.pop();
            k--;
        }

        StringBuilder ans = new StringBuilder();
        while (!stk.isEmpty()) {
            ans.insert(0, stk.pop());
        }

        System.out.println(ans.toString());
        while (ans.length() > 1 && ans.charAt(0) == '0') {
            ans.deleteCharAt(0);
        }
        
        if (ans.length() == 0) {
            return "0";
        }
        return ans.toString();
    }
}