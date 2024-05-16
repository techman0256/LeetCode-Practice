class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int parent[] = new int[n * m];
        int size[] = new int[n * m];
        
        for (int i=0; i < size.length; i++) {
            size[i] = 1;
            parent[i] = i;
        }

        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                int u = (m * i) + j;
                if (grid[i][j] == 1 && i - 1 >= 0 && grid[i - 1][j] == 1) {
                    int v = (m *(i - 1)) + j; 
                    unionFind(u, v, parent, size);
                    
                }
                if (grid[i][j] == 1 && i + 1 < n && grid[i + 1][j] == 1) {
                    int v = (m *(i + 1)) + j; 
                    unionFind(u, v, parent, size);
                    
                }
                if (grid[i][j] == 1 && j - 1 >= 0 && grid[i][j - 1] == 1) {
                    int v = (m * i) + j - 1;
                    unionFind(u, v, parent, size);
                }
                if (grid[i][j] == 1 && j + 1 < m && grid[i][j + 1] == 1) {
                    int v = (m * i) + j + 1;
                    unionFind(u, v, parent, size);
                    
                }
            }
        }
        int max = 0;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                // int u = (m * i) + j;
                int conn = 1;

                if ( grid[i][j] == 0 ) {
                    int neigh[] = new int[]{(m * (i - 1)) + j, (m * (i + 1)) + j, (m * i) + j - 1, (m * i) + j + 1};
                    // int row[] = new int[]{-1, 1, 0, 0};
                    // int col[] = new int[]{0, 0, -1, 1};
                    int isOne[] = new int[4];
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                       isOne[0] = 1; 
                    }
                    if (i + 1 < n && grid[i + 1][j] == 1) {
                        isOne[1] = 1;
                    }
                    if ( j - 1 >= 0 && grid[i][j - 1] == 1) {
                        isOne[2] = 1;
                    }
                    if (j + 1 < m && grid[i][j + 1] == 1) {
                        isOne[3] = 1;
                    }

                    HashSet<Integer> set = new HashSet<Integer>();
                    for (int l=0; l < 4; l++) {
                            // System.out.println("hi" + " " + isOne[l]);
                        if (neigh[l] >= 0 && neigh[l] < n * m && isOne[l] == 1) {
                            set.add(findParent(neigh[l], parent));

                        } 
                    }
                    
                    for (Integer up : set) {
                        // System.out.println(up + " " + size[up]);
                        conn += size[up];
                    }
                }
                max = Math.max(max, conn);
                


            }
        }

        // System.out.println(Arrays.toString(size));
        // System.out.println(Arrays.toString(size));
        if (max == 1) {
            for (int i=0; i < n; i++) {
                max = Math.max(size[i], max);
            }
        }
        
        return max;
    }
    static int findParent(int node, int parent[]) {
        if (node == parent[node]) return node;

        return parent[node] = findParent(parent[node], parent);
    }
    static void unionFind(int u, int v, int parent[], int size[]) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu == pv) return;

        // System.out.println("me bhi hu");
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return;
    }
}