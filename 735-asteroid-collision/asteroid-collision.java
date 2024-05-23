class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;

        Stack<Integer> stk = new Stack<Integer>();
        boolean exist[] = new boolean[n];
        Arrays.fill(exist, true);

        for (int i=0; i < n; i++) {
            if (asteroids[i] > 0) {
                stk.push(i);
            } else {
                if (stk.isEmpty()) {
                    continue;
                }
                while (!stk.isEmpty() && Math.abs(asteroids[i]) > asteroids[stk.peek()]) {
                    exist[stk.pop()] = false;
                }
                if (stk.isEmpty()) {
                    continue;
                }
                else if (Math.abs(asteroids[i]) < asteroids[stk.peek()]) {
                    exist[i] = false;
                }
                else if (Math.abs(asteroids[i]) == asteroids[stk.peek()]) {
                    exist[i] = false;
                    exist[stk.pop()] = false;
                } 


                // if (stk.isEmpty()) {
                //     continue;
                // }
                // else if (Math.abs(asteroids[i]) >= asteroids[stk.peek()]) {
                //     while (!stk.isEmpty() && Math.abs(asteroids[i]) > asteroids[stk.peek()]) {
                //         int burst = stk.pop();
                //         exist[burst] = false;
                //     } 
                //     if (!stk.isEmpty()) {
                //         exist[i] = false;
                //     } 
                //     if (asteroids[stk.peek()] == asteroids[i]) {
                //         exist[stk.peek()] = false;
                //         stk.pop();
                //     }             
                // } else if (Math.abs(asteroids[i]) < asteroids[stk.peek()]){
                //     exist[i] = false;
                // } else {
                //     exist[stk.peek()] = false;
                //     stk.pop();
                //     exist[i] = false;
                // }
            }
        }

        
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i=0; i < n; i++) {
            if (exist[i] == true) {
                ans.add(asteroids[i]);
            }
        }

        int array[] = new int[ans.size()];
        for (int i=0; i < ans.size(); i++) {
            array[i] = ans.get(i);
        }


        return array;
    }
}