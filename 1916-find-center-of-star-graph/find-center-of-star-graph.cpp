class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int V = edges.size() + 1;
        // int indeg[V] = {0}
        vector<int> indeg(V + 1, 0);
        for (int i=0; i < V - 1; i++) {
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }

        for (int i=0; i <= V; i++) {
            if (indeg[i] == V - 1) {
                return i;
            }
        }

        return 0;
    }
};