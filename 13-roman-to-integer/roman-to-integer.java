class Solution {
    public int romanToInt(String s) {
        int map[] = new int[]{1, 5, 10, 50, 100, 500, 1000};
        Character[] roman = new Character[]{'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        HashMap<Character, Integer> hm = new HashMap<Character, Integer>();
        for (int i=0; i < map.length; i++) {
            hm.put(roman[i], map[i]);
        }

        int curr = 1;
        int num = 0;
        for (int i=s.length() - 1; i >= 0; i--) {
            if (hm.get(s.charAt(i)) == curr) {
                num += curr;
            } else if (hm.get(s.charAt(i)) < curr) {
                num -= hm.get(s.charAt(i));
            } else {
                curr = hm.get(s.charAt(i));
                num += curr;
            }
        }  
        return num;  
    }
}