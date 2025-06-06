class Solution {
public:    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long long, long long>> adj[n];
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dis(n, LONG_MAX);
        vector<long long> ways(n);
        
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        long long mod = 1e9+ 7;
        
        while(!pq.empty()){
            
            long long nodeWt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
                
            // if(nodeWt > dis[node]) continue;
            
            for(auto i: adj[node]){
                
                long long child = i.first;
                long long childWt = i.second;
                
                if(childWt + nodeWt < dis[child]){
                    dis[child] = childWt + nodeWt;
                    pq.push({dis[child], child});
                    ways[child] = ways[node];
                }
                else if(childWt + nodeWt == dis[child]){
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
        
    }
};