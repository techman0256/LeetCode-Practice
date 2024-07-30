// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();
//         vector<int> vis(n,0) , dis(n,INT_MAX);
//         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;

//         q.push({0 , 0});
//         dis[0] = 0;
//         while(!q.empty())
//         {
//             auto[wt , node] = q.top();
//             q.pop();
//             if(vis[node] == 1) continue;
//             vis[node] = 1;

//             for(int i=0 ; i<n ; i++)
//             {
//                 if(vis[i] == 0 && dis[i] > (abs(points[node][0] - points[i][0])+
//                                             abs(points[node][1] - points[i][1])))
//                 {
//                     dis[i] = (abs(points[node][0] - points[i][0])+
//                               abs(points[node][1] - points[i][1]));
//                     q.push({dis[i] , i});
//                 }
//             }
//         }

//         int res = 0;
//         for(auto i:dis)
//         res+=i;

//         return res;
//     }
// };

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vis(n, 0);
        vector<int> dis(n, INT_MAX);

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push( {0, 0} );
        dis[0] = 0;
        while ( !pq.empty() ) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node] == 1) continue;
            vis[node] = 1;

            for (int i=0; i < n; i++) {
                if (vis[i] == 0 && dis[i] > abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1])) {
                    dis[i] = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push( {dis[i], i} );
                }
            }



        }

        int res = 0;
        for ( auto i : dis ) {
            res += i;
        }
        return res;
    }
};