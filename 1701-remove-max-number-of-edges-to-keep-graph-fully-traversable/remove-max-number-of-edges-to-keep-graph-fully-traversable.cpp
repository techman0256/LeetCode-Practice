// class DSU {
//     public:
//     int parent[];
//     int size[];

//     DSU(n) {
//         parent[n + 1];
//         size[n + 1];
//         for (int i=1; i <= n + 1; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }



//     }
// }


class Solution {
public:
    int find(vector<int> &parent, int node) {
        if (node == parent[node]) {
            return node;
        }

        return find(parent, parent[node]);
    }
    void unionBySize(vector<int> &parent, vector<int> &size, int u, int v) {
        int pu = find(parent, u);
        int pv = find(parent, v);

        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            size[pu] = 0;
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            size[pv] = 0;
        }
    }
    static bool compare(vector<int> a, vector<int> b) {
        return a[0] > b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n + 1);
        vector<int> parentB(n + 1);
        vector<int> sizeA(n + 1, 1);
        vector<int> sizeB(n + 1, 1);

        for (int i=0; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
        }

        sort(edges.begin(), edges.end(), compare);

        int cnt = 0;
        int i = 0;
        for ( auto edge : edges) {
            // cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
            if (edge[0] == 1) {
                int u = edge[1];
                int v = edge[2];

                if (find(parentA, u) == find(parentA, v)) {
                    cnt++;
                    // cout << i << " 1 " << endl;
                    continue;
                } else {
                    unionBySize(parentA, sizeA, u, v);
                }
            } else if (edge[0] == 2) {
                int u = edge[1];
                int v = edge[2];

                if (find(parentB, u) == find(parentB, v)) {
                    cnt++;
                    // cout << i << " 2 " << endl;
                    continue;
                } else {
                    unionBySize(parentB, sizeB, u, v);
                }

            } else if (edge[0] == 3) {
                int u = edge[1];
                int v = edge[2];
                
                if (find(parentA, u) == find(parentA, v) && find(parentB, u) == find(parentB, v)) {
                    cnt++;
                    continue;
                }
                unionBySize(parentA, sizeA, u, v);
                unionBySize(parentB, sizeB, u, v);             

            }
            i++;
        }

        int islandA = 0;
        int islandB = 0;
        for (int i=1; i <= n; i++) {
            if (sizeA[i] > 0) islandA++;
            if (sizeB[i] > 0) islandB++;
        }

        if (islandA > 1 || islandB > 1) {
            return -1;
        }
        
        return cnt;
        
    }
};