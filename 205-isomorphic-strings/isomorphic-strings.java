class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> hm = new HashMap<>();
        String comp1 = "";
        for (int i=0; i < s.length(); i++) {
            if (hm.containsKey(s.charAt(i))) {
                comp1 += "" + hm.get(s.charAt(i));
            } else {
                comp1 += t.charAt(i);
                hm.put(s.charAt(i), t.charAt(i));
            }
        }
        hm.clear();

        String comp2 = "";
        for (int i=0; i < t.length(); i++) {
            if (hm.containsKey(t.charAt(i))) {
                comp2 += "" + hm.get(t.charAt(i));
            } else {
                comp2 += s.charAt(i);
                hm.put(t.charAt(i), s.charAt(i));
            }
        }

        if (comp1.equals(t) && comp2.equals(s)) return true;
        else return false;
    }
}