class Solution {
    public String largestOddNumber(String num) {
        int temp = 0;
        for (int i=num.length() - 1; i >= 0; i--) {
            String mid = num.substring(i , i + 1);
            if (mid.length() > 0) temp = Integer.parseInt(mid);
            if (temp % 2 == 1) {
                return num.substring(0, i + 1);
            }
        }
        
        return "";
    }
}