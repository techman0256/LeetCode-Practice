class Solution {
public:
    bool DFS(int node,vector<int> &ans, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neigh : adj[node]) {
            if (vis[neigh] == 0) {
                bool check = DFS(neigh, ans, vis, pathVis, adj);
                if (check == false) return check;
            } else if (pathVis[neigh] == 1) {
                return false;
            }
        }

        pathVis[node] = 0;
        ans.insert(ans.begin(), node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        // cout << prerequisites.size() << " " << numCourses ;
        for (int i=0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    


        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        vector<int> ans;

        for (int i=0; i < numCourses; i++) {
            if (vis[i] == 0) {
                bool check = DFS(i, ans, vis, pathVis, adj);
                if (check == false) {
                    return {};
                }
            }
        }

        return ans;

    }
};