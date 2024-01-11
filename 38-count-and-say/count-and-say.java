class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        String s = countAndSay(n - 1);
        String ans = "";
        Character now = s.charAt(0);
        int occu = 0;


        for (int i=0; i < s.length(); i++) {
            if (now != s.charAt(i)) {
                // System.out.println("hello");
                ans += Integer.toString(occu) + now;
            
                // System.out.println("hi");
                now = s.charAt(i);
                occu = 0;
            } 
            occu++;
        }
        ans += Integer.toString(occu) + now;
        // System.out.println(ans + " " + n);
        return ans;
    }
}