class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();
        String s1 = s.substring(0, n/2);
        String s2 = s.substring(n/2);
        int vowels1 = 0, vowels2 = 0;
        
        for (int i=0; i < n/2; i++) {
            if (s1.charAt(i) == 'A' || s1.charAt(i) == 'E' || s1.charAt(i) == 'I' || s1.charAt(i) == 'O' || s1.charAt(i) == 'U' || s1.charAt(i) == 'a' || s1.charAt(i) == 'e' || s1.charAt(i) == 'i' || s1.charAt(i) == 'o' || s1.charAt(i) == 'u') {
                vowels1++;
            }
            if (s2.charAt(i) == 'A' || s2.charAt(i) == 'E' || s2.charAt(i) == 'I' || s2.charAt(i) == 'O' || s2.charAt(i) == 'U' || s2.charAt(i) == 'a' || s2.charAt(i) == 'e' || s2.charAt(i) == 'i' || s2.charAt(i) == 'o' || s2.charAt(i) == 'u') {
                vowels2++;
            }
        } 
        
        return vowels1 == vowels2;
    }
}