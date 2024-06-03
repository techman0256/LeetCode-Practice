class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdeg(n, 0);
        vector<int> ans;
        vector<vector<int>> adjRev(n);

        queue<int> bfs;
        for (int i=0; i < n; i++) {
            outdeg[i] = graph[i].size();
            if (outdeg[i] == 0) {
                bfs.push(i);
                ans.push_back(i);
            }
            for (int j=0; j < graph[i].size(); j++) {
                adjRev[graph[i][j]].push_back(i); 
                // cout << graph[i][j] << " " << i << endl;
            }
        }   

        while ( !bfs.empty() ) {
            int top = bfs.front();
            bfs.pop();

            for ( auto neigh : adjRev[top] ) {
                outdeg[neigh] -= 1;
                if (outdeg[neigh] == 0) {
                    bfs.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};