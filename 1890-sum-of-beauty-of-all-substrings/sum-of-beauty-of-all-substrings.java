class Solution {
    public int beautySum(String s) {
        int map[][] = new int[26][s.length()];
        
        //initializing hashmap using array
        for (int i=0; i < s.length(); i++) {
            int charIdx = s.charAt(i) - 'a';
            if (i != 0) {
                for (int j=0; j < 26; j++) {
                    map[j][i] = map[j][i - 1];
                }
            }
            map[charIdx][i] += 1;
        }

        int sum = 0;
        for (int i=0; i < s.length(); i++) {
            for (int j=i+1; j < s.length(); j++) {
                // System.out.println(i + " " + j + " " + beautySS(i, j, s, map));
                
                sum += beautySS(i, j, s, map);
            }
        }

        return sum;
    }
    static int beautySS(int start, int end, String s, int map[][]) {
        int diff[] = new int[26];
        // if (start == 0) diff = start[]
        for (int i=0; i < 26; i++) {
            if (start != 0) {
                diff[i] = map[i][end] - map[i][start - 1];
            } else {
                diff[i] = map[i][end];
            }
        }

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i=0; i < 26; i++) {
            if (diff[i] != 0) {
                max = Math.max(max, diff[i]);
                min = Math.min(min, diff[i]);
            }
        }
        return max - min;
    }
}