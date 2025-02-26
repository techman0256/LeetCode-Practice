class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i=0; i < n; i++) {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }

        priority_queue<int> pq;
        for (int i=0; i < n; i++) {
            for (int j=0; j < limits[i]; j++) {
                pq.push(grid[i][j]);
            }
        }

        long long sum = 0;
        for (int i=0; i < k; i++) {

            sum += pq.top();
            pq.pop();
        }

        return sum;

    }


};