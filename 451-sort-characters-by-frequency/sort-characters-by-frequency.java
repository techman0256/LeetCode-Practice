import java.util.*;

class Solution {
    public String frequencySort(String s) {
        SortedMap<Character, Integer> sm = new TreeMap<>();
        
        for (int i=0; i < s.length(); i++) {
            if (sm.containsKey(s.charAt(i))) {
                sm.put(s.charAt(i), sm.get(s.charAt(i)) + 1);
            } else {
                sm.put(s.charAt(i), 1);
            }
        }
        
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        for (Map.Entry<Character, Integer> entry: sm.entrySet()) {
            pq.add(entry);
        }

        String ans = "";
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            // System.out.println(entry.getValue());
            int occ = entry.getValue();
            for (int i=0; i < occ; i++) {
                ans += "" + entry.getKey();
            }

        }

        return ans;
    }
}