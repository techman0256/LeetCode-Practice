class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n);
        vector<int> size(n, 1);
        vector<int> cost(n, INT_MAX);
        for (int i=0; i < n; i++) {
            parent[i] = i;
        }

        for (int i=0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            unionBySize(parent, size, cost, u, v, weight);
        }

        vector<int> ans;
        for (int i=0; i < query.size(); i++) {
            int u = query[i][0];
            int v = query[i][1];
            int pu = findParent(parent, u);
            int pv = findParent(parent, v);

            if (pu == pv){
                ans.push_back(cost[pu]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
    int findParent(vector<int> &parent, int node) {
        if (node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent, parent[node]);
    }
    void unionBySize(vector<int> &parent, vector<int> &size, vector<int> &cost, int u, int v, int weight) {
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu == pv) {
            cost[pu] &= weight;
            return;
        }
        cost[pv] = (cost[pv] & cost[pu]) & weight;
        // cost[pv] &= cost[pu]
        parent[pu] = pv;
        // size[pu] = -1;
        // if (size[pv] < size[pu]) {
        //     size[pu] += size[pv];
        //     cost[pu] = (cost[pv] & cost[pu]) & weight;
        //     parent[pv] = pu;
        // } else {
        //     size[pv] += size[pu];
        //     cost[pu] = (cost[pv] & cost[pu]) & weight;
        //     parent[pu] = pv;
        // }
    }

};