class Solution {
public:
    bool DFS(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neigh : adj[node]) {
            if (vis[neigh] == 0) {
                bool check = DFS(neigh, vis, pathVis, adj);
                if (check == false) return check;
            } else if (pathVis[neigh] == 1) {
                return false;
            }
        }
        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i=0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    

        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i=0; i < numCourses; i++) {
            if (vis[i] == 0) {
                bool check = DFS(i, vis, pathVis, adj);
                if (check == false) return false;
            }
        }

        return true;
    }
};