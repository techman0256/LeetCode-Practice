struct Compare {
    bool operator()(const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) {
        // Compare based on the second element of the inner pair
        if (p1.first.second == p2.first.second) {
             p1.second > p2.second;
        }
        return p1.first.second > p2.first.second;
    }
    };

class Solution {
    
public:
    // typedef pair<int, int>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< vector<pair<int, int>> > adj(n);
        for (int i=0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({ flights[i][1], flights[i][2]} );   
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<pair<int, int>, int>> bfs;

        bfs.push( {{src, 0}, -1} );
        dist[src] = 0;

        while ( !bfs.empty() ) {
            int node = bfs.front().first.first;
            int price = bfs.front().first.second;
            int stops = bfs.front().second;
            bfs.pop();
            cout << node << " " << price << " " << stops << endl;
                // if (stops > k) continue;
            for ( auto neigh : adj[node] ) {
                int to = neigh.first;
                int cost = neigh.second;

                if (stops + 1 <= k && dist[to] > cost + price) {
                    dist[to] = cost + price;
                    bfs.push({ {to, dist[to]}, stops + 1} );

                }
                // if (stops + 1 <= k) {
                // }
            }
        }

        if (dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};