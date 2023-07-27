class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;



        int x = 0, y = n - 1;

        while (y >= 0 && x < m) {
            // 0 - left, 1 -  right, 2 - up, 3 - down
            int xdir[] = new int[] {x - 1, x, x + 1, x};
            int ydir[] = new int[] {y, y - 1, y, y + 1};
            int neigh[] = new int[4];
            Arrays.fill(neigh, -1);

            int maxx = x;
            int maxy = y;

            for (int i=0; i < 4; i++) {
                int p = xdir[i];
                int q = ydir[i];
                if (p >= 0 && q >= 0 && p < m && q < n && mat[p][q] > mat[maxx][maxy]) {
                    maxx = p;
                    maxy = q;
                }
            }

            if (x == maxx && y == maxy) return new int[] {maxx, maxy};
            else {
                x = maxx;
                y = maxy;
            }
            
        }

        return new int[] {-1, -1};
    }
}