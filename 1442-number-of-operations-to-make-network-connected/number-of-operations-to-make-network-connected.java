class Solution {
    public int makeConnected(int n, int[][] connections) {
        int cables = connections.length;

        int parent[] = new int[n];
        for (int i=0; i < n; i++) {
            parent[i] = i;
        }

        int size[] = new int[n];
        Arrays.fill(size, 1);

        int redundant = 0;
        for (int i=0; i < cables; i++) {
            redundant += unionBySize(connections[i][0], connections[i][1], size, parent);
        }

        int island = 0;
        for (int i=0; i < n; i++) {
            if (size[i] != 0) island++;
        }
        // System.out.println(redundant);
        // System.out.println(Arrays.toString(size));
        // System.out.println(Arrays.toString(parent));

        if (island - 1 <= redundant) {
            return island - 1;
        } else {
            return -1;
        }

    }
    static int findParent(int parent[], int node) {
        if (node == parent[node]) return node;

        return parent[node] = findParent(parent, parent[node]);
    }
    static int unionBySize(int u, int v, int size[], int parent[]) {
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu == pv) return 1; 

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

        return 0;
    }
}