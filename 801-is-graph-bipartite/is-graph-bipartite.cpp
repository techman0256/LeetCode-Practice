class Solution {
public:
    bool DFS(int node, vector<int> &vis, vector<vector<int>> &graph) {
        cout << node << endl;
        for (auto neigh : graph[node]) {
            if (vis[neigh] != 0 && vis[neigh] == vis[node]) {
                return false;
            } 
            if (vis[neigh] == 0) {
                if (vis[node] == 1) vis[neigh] = 2;
                else vis[neigh] = 1;

                bool check = DFS(neigh, vis, graph);
                if (check == false) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis (V, 0);

        for (int i=0; i < V; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
               
                bool twoCol = DFS(i, vis, graph);
                if (twoCol == false) return false;
            }
        }
        
        return true;
    }
};