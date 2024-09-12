class Solution {
    public int minimumCardPickup(int[] cards) {
        int n = cards.length;
        int win = Integer.MAX_VALUE;
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        int start = 0, end = 0;
        while (end < n) {
            while (hm.getOrDefault(cards[end], 0) == 1) {
                // System.out.println(start + " " + end);
                win = Math.min(end - start + 1, win);
                hm.put(cards[start], hm.get(cards[start]) - 1);
                start++;
            } 
            // else {
            // }
            hm.put(cards[end], hm.getOrDefault(cards[end], 0) + 1);
            end++;
        }

        // while (start < n && ) {

        // }

        if (win == Integer.MAX_VALUE) {
            return -1;
        }
        return win;
    }
}