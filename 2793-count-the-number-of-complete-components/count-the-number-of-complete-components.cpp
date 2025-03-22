class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> degree;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        degree.resize(n, 0);
        for (int i=0; i < n; i++) {
            parent[i] = i;
        }

        for (int i=0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u] += 1;
            degree[v] += 1;
            unionBySize(u, v);
        }

        map<int, int> comp;
        vector<int> deleted;
        for (int i=0; i < n; i++) {
            if (size[i] > 0) {
                comp[i] = size[i];
            }
        }

        // for (int i=0; i < n; i++) {
        //     cout << parent[i] << " " ;
        // }
        // cout << endl;
        // for (int i=0; i < n; i++) {
        //     cout << size[i] << " " ;
        // }
        // cout << endl;

        // for (int i=0; i < n; i++) {
        //     cout << degree[i] << " " ;
        // }
        // cout << endl;



        for (int i=0; i < n; i++) {
            int pi = find(i);
            if (comp.find(pi) != comp.end() && degree[i] != comp[pi] - 1) {
                comp.erase(pi);
            }
        }


        return comp.size();
    }
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return;
        }

        if (size[pv] < size[pu]) {
            size[pu] += size[pv];
            parent[pv] = pu;
            size[pv] = 0;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
            size[pu] = 0;
        }

        return;
    }
};