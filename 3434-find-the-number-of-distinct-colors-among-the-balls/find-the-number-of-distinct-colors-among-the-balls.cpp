class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        // int balls[limit + 1] = {0};
        unordered_map<int, int> balls;
        unordered_map<int, int> dist;
        vector<int> ans;

        for ( auto q : queries ) {
            if ( balls.count(q[0]) ) {
                dist[ balls[q[0]] ]--;
                if (dist[ balls[q[0]] ] == 0) {
                    dist.erase(balls[q[0]]);
                }
            }
            dist[q[1]]++;
            balls[q[0]] = q[1];
            ans.push_back(dist.size());
        }

        return ans;
    }
};