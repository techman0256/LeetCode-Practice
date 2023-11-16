class Solution {
    public int numberOfSubstrings(String s) {
        Queue<Integer> a = new LinkedList<>();
        Queue<Integer> b = new LinkedList<>();
        Queue<Integer> c = new LinkedList<>();


        for (int i=0; i < s.length(); i++) {
            Character curr = s.charAt(i);
            if (curr == 'a') a.add(i);
            else if (curr == 'b') b.add(i);
            else c.add(i);
        }

        int ans = 0;
        for (int left=0; left < s.length(); left++) {
            if (!a.isEmpty() && !c.isEmpty() && !b.isEmpty()) {
                // System.out.println(a.peek() + " " + b.peek() + " " + c.peek());

                int right = Math.max(a.peek(), Math.max(b.peek(), c.peek()));
                ans += s.length() - right;
                // System.out.println(ans +  " " + left + " " + right);

            }

            while (!a.isEmpty() && a.peek() <= left) {
                a.poll();
            }
            while (!b.isEmpty() && b.peek() <= left) {
                b.poll();
            }
            while (!c.isEmpty() && c.peek() <= left) {
                c.poll();
            }
        }

        return ans;
    }
}