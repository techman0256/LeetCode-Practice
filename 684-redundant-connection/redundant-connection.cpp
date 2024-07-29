class Solution {
public:

    vector<int> size;
    vector<int> parent;
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    int findUnionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        // cout << pv << " " << pu << " " << u  << " " << v << endl;
        if (pv == pu) {
            return 1;
        }

        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        // cout << u << " " << v << " " << findParent(u) << " " << findParent(v) << endl;

        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj;

        for (int i=0; i <= 1000; i++) {
            // parent[i] = i;
            // size[i] = 0;
            parent.push_back(i);
            size.push_back(1);
        }

        vector<int> ans;

        for (int i=0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if ( findUnionBySize(u, v) == 1 ) {
                cout << " HI " << endl;
                ans =  edges[i];
            }
        }
        return ans;
    }
};