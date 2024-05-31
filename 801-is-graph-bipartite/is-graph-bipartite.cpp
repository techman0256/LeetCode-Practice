class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis (V, 0);

        for (int i=0; i < V; i++) {
            if (vis[i] == 0) {
                queue<int> bfs;
                bfs.emplace(i);
                vis[i] = 1;

                while ( !bfs.empty() ) {
                    int node = bfs.front();
                    bfs.pop();

                    for (auto neigh : graph[node]) {
                        if (vis[neigh] != 0 && vis[neigh] == vis[node] ) {
                            return false;
                        }
                        if (vis[neigh] == 0) {
                            if (vis[node] == 1) vis[neigh] = 2;
                            else vis[neigh] = 1;

                            bfs.emplace(neigh);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};