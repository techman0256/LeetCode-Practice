class Solution {
    public int characterReplacement(String s, int k) {
        int ans = 0;

        int[] hm = new int[26];
        int max = 0;
        int argmax = -1;

        // HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        // PriorityQueue<Pair> pq = new PriorityQueue<Pair>((a, b) -> b.occurance - a.occurance);

        int left = 0, right = 0;

        while (right < s.length()) {
            int curr = s.charAt(right) - 'A';
            hm[curr] +=1;
            if (hm[curr] > max) {
                max = hm[curr];
                argmax = curr;
            }

            int window = right - left + 1;
            if (window - max > k) {
                int leftmost = s.charAt(left) - 'A';
                hm[leftmost] -= 1;
                left++;
            } else {
                ans = Math.max(ans, window);
            }
            right++;
        }


        return ans;
    }
}

// class Pair {
//     Character letter;
//     int occurance;

//     Pair(Character x, int y) {
//         this.letter = x;
//         this.occurance = y;
//     }
// }