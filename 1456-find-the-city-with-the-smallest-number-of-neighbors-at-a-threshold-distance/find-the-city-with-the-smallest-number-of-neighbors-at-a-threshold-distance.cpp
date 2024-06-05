class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i=0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back( {edges[i][1], edges[i][2]} );
            adj[edges[i][1]].push_back( {edges[i][0], edges[i][2]} );
        }

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        vector<int> reach(n, 0);

        for (int i=0; i < n; i++) {
            priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > bfs;
            bfs.push( {i, 0} );
            dist[i][i] = 0;

            while ( !bfs.empty() ) {
                int node = bfs.top().first;
                int len = bfs.top().second;
                bfs.pop();

                for ( auto neigh : adj[node] ) {
                    int vert = neigh.first;
                    int cost = neigh.second;

                    if (dist[i][vert] > cost + len) {
                        dist[i][vert] = cost + len;
                        bfs.push( {vert, dist[i][vert]} );
                    }
                }
            }

            for (int j=0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reach[i]++;
                }
            }
        }

        int ans = 0;
        for (int i=0; i < n; i++) {
            if (reach[ans] >= reach[i]) {
                ans = i;
            }
        }

        return ans;
    }
};