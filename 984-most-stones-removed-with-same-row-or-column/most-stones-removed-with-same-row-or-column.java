class Solution {
    public int removeStones(int[][] stones) {
        int n = 0, m = 0;

        for (int i=0; i < stones.length; i++) {
            n = Math.max(n, stones[i][0]);
            m = Math.max(m, stones[i][1]);
        }
        n += 1;
        m += 1;
        
        
        int parent[] = new int[n + m];
        int size[] = new int[n + m];

        for (int i=0; i < size.length; i++) {
            size[i] = 1;
            parent[i] = i;
        }

        for (int i=0; i < stones.length; i++) {
            int u = stones[i][0];
            int v = stones[i][1] + n;

            unionBySize(u, v, parent, size);
        }
        
        int island = 0;
        for (int i=0; i < size.length; i++) {
            if (size[i] != 0 && size[i] != 1) island++;
        }
        System.out.println(Arrays.toString(size));

        return stones.length - island;
    }
    static int findParent(int parent[], int node) {
        if (parent[node] == node) return node;

        return parent[node] = findParent(parent, parent[node]);
    }
    static void unionBySize(int u, int v, int parent[], int size[]) {
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if ( pu == pv ) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            size[pu] = 0;
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
            size[pv] = 0;
        }

        return;
    }
}